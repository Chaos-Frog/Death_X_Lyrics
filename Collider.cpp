#include "Collider.h"

Collider::Collider(Vector2* pos, Vector2 relative) {
    basePos = pos;
    relativePos = relative;

    parameter.type = -1;
    parameter.centerPos = *basePos + relativePos;
    parameter.pos1 = Vector2(0, 0);
    parameter.pos2 = Vector2(0, 0);
    parameter.radius = 0.0;
}
Collider::~Collider(){}
void Collider::Update(){}
void Collider::DebugDraw(){}
ColliderParam Collider::GetParameter() const {
    return parameter;
}

Circle_C::Circle_C(Vector2* pos, Vector2 relative, double r) : Collider(pos, relative){
    parameter.type = CIRCLE;
    parameter.radius = r;
}

void Circle_C::Update() {
    parameter.centerPos = *basePos + relativePos;
}

void Circle_C::DebugDraw() {
    DrawCircle(round(parameter.centerPos.x), round(parameter.centerPos.y), parameter.radius, GetColor(0, 255, 0));
}


Box_C::Box_C(Vector2* pos, Vector2 relative, double xl, double yl) : Collider(pos, relative){
    parameter.type = BOX;
    xLength = xl;
    yLength = yl;

    parameter.pos1 = Vector2(parameter.centerPos.x - (xl/2), parameter.centerPos.y - (yl/2));
    parameter.pos2 = Vector2(parameter.centerPos.x + (xl/2), parameter.centerPos.y + (yl/2));
}

void Box_C::Update() {
    parameter.centerPos = *basePos + relativePos;
    parameter.pos1 = Vector2(parameter.centerPos.x - (xLength/2), parameter.centerPos.y - (yLength/2));
    parameter.pos2 = Vector2(parameter.centerPos.x + (xLength/2), parameter.centerPos.y + (yLength/2));
}

void Box_C::DebugDraw() {
    DrawBox(round(parameter.pos1.x), round(parameter.pos1.y), round(parameter.pos2.x), round(parameter.pos2.y), GetColor(0, 255, 0), TRUE);
}


Line_C::Line_C(Vector2* pos, Vector2 relative, double len, double degAngle) : Collider(pos, relative){
    parameter.type = LINE;
    length = len;
    angle = degAngle;

    double xp = (length/2) * cos(angle * (M_PI/180)) + parameter.centerPos.x;
    double yp = (length/2) * sin(angle * (M_PI/180)) + parameter.centerPos.y;
    parameter.pos1 = Vector2(xp, yp);
    parameter.pos2 = Vector2(-xp, -yp);
}

void Line_C::Update() {
    parameter.centerPos = *basePos + relativePos;
    double xp = (length/2) * cos(angle * (M_PI/180)) + parameter.centerPos.x;
    double yp = (length/2) * sin(angle * (M_PI/180)) + parameter.centerPos.y;
    parameter.pos1 = Vector2(xp, yp);
    parameter.pos2 = Vector2(-xp, -yp);
}

void Line_C::DebugDraw() {
    DrawLine(round(parameter.pos1.x), round(parameter.pos1.y), round(parameter.pos2.x), round(parameter.pos2.y), GetColor(0, 255, 0));
}


/* Õ“Ë”»’èˆ—ŒS */
bool CollisionCheck(const Collider* c1, const Collider* c2) {
    ColliderParam cp1, cp2;
    cp1 = c1->GetParameter();
    cp2 = c2->GetParameter();

    if(cp1.type == CIRCLE) {
        if(cp2.type == CIRCLE) {
            return CC_Collision(&cp1.centerPos, cp1.radius, &cp2.centerPos, cp2.radius);
        } else if(cp2.type == BOX) {
            return CB_Collision(&cp1.centerPos, cp1.radius, &cp2.pos1, &cp2.pos2);
        } else if(cp2.type == LINE) {
            return CL_Collision(&cp1.centerPos, cp1.radius, &cp2.pos1, &cp2.pos2);
        } else {
            return false;
        }
    } else if(cp1.type == BOX) {
        if(cp2.type == CIRCLE) {
            return CB_Collision(&cp2.centerPos, cp2.radius, &cp1.pos1, &cp1.pos2);
        } else if(cp2.type == BOX) {
            return BB_Collision(&cp1.pos1, &cp1.pos2, &cp2.pos1, &cp2.pos2);
        } else {
            return false;
        }
    } else if(cp1.type == LINE) {
        if(cp2.type == CIRCLE) {
            return CL_Collision(&cp2.centerPos, cp2.radius, &cp1.pos1, &cp1.pos2);
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool CC_Collision(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2) {
    const Vector2 dif = *v2 - *v1;
    const double radius = cr1 + cr2;
    return pow(dif.x, 2) + pow(dif.y, 2) <= pow(radius, 2);
}

bool BB_Collision(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4) {
    if(v1->x <= v4->x && v2->x >= v3->x && v1->y <= v4->y && v2->y >= v3->y) {
        return true;
    } else {
        return false;
    }
}

bool CB_Collision(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2) {
    Vector2 nearest;
    if(v->x < v1->x)      nearest.x = v1->x;
    else if(v->x > v2->x) nearest.x = v2->x;
    else                  nearest.x = v->x;

    if(v->y < v1->y)      nearest.y = v1->y;
    else if(v->y > v2->y) nearest.y = v2->y;
    else                  nearest.y = v->y;

    return CC_Collision(v, cr, &nearest, 0.0f);
}

bool CL_Collision(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2) {
    if(CC_Collision(v, cr, lv1, 0) || CC_Collision(v, cr, lv2, 0)) return true;

    const Vector2 lineV = *lv2 - *lv1;
    const Vector2 lineCV = *v - *lv1;
    Vector2 proj;
    const double dot = pow(lineV.x, 2) + pow(lineV.y, 2);
    if(dot < 0) {
        const double dotP = (lineV.x * lineCV.x) + (lineV.y * lineCV.y);
        proj = lineV * (dotP / dot);
    } else {
        proj = lineCV;
    }
    const Vector2 nearest = *lv1 + proj;

    return CC_Collision(v, cr, &nearest, 0) &&
        pow(proj.x, 2) + pow(proj.y, 2) <= pow(lineV.x, 2) + pow(lineV.y, 2) &&
        0 <= (proj.x * lineV.x) + (proj.y * lineV.y);

}