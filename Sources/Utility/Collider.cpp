#include "Collider.h"

/* Collider Base */
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
ColliderParam Collider::GetParameter() const {
    return parameter;
}


/* Collider Circle */
Circle_C::Circle_C(Vector2* pos, Vector2 relative, double r) : Collider(pos, relative){
    parameter.type = CIRCLE;
    parameter.radius = r;
}

void Circle_C::Update() {
    parameter.centerPos = *basePos + relativePos;
}


/* Collider Box */
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


/* Collider Line */
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


/* Õ“Ë”»’èˆ—ŒS */
bool CheckCollision(const Collider* c1, const Collider* c2) {
    ColliderParam cp1, cp2;
    cp1 = c1->GetParameter();
    cp2 = c2->GetParameter();

    switch(cp1.type) {
        case CIRCLE:
            switch(cp2.type) {
                case CIRCLE:
                    return CC_Collision(&cp1.centerPos, cp1.radius, &cp2.centerPos, cp2.radius);
                    break;

                case BOX:
                    return CB_Collision(&cp1.centerPos, cp1.radius, &cp2.pos1, &cp2.pos2);
                    break;
                
                case LINE:
                    return CL_Collision(&cp1.centerPos, cp1.radius, &cp2.pos1, &cp2.pos2);
                    break;

                default:
                    return false;
                    break;
            }
            break;
        
        case BOX:
            switch(cp2.type) {
                case CIRCLE:
                    return CB_Collision(&cp2.centerPos, cp2.radius, &cp1.pos1, &cp1.pos2);
                    break;
                
                case BOX:
                    return BB_Collision(&cp1.pos1, &cp1.pos2, &cp2.pos1, &cp2.pos2);
                    break;
                
                case LINE:
                    return BL_Collision(&cp1.pos1, &cp1.pos2, &cp2.pos1, &cp2.pos2);
                    break;

                default:
                    return false;
                    break;
            }
            break;

        case LINE:
            switch(cp2.type) {
                case CIRCLE:
                    return CL_Collision(&cp2.centerPos, cp2.radius, &cp1.pos1, &cp1.pos2);
                    break;

                case BOX:
                    return BL_Collision(&cp2.pos1, &cp2.pos2, &cp1.pos1, &cp1.pos2);
                    break;

                case LINE:
                    return LL_Collision(&cp1.pos1, &cp1.pos2, &cp2.pos1, &cp2.pos2);
                    break;

                default:
                    return false;
                    break;
            }
            break;

        default:
            return false;
            break;
    }
}

bool CC_Collision(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2) {
    const Vector2 dif = *v2 - *v1;
    const double radius = cr1 + cr2;
    return pow(dif.x, 2) + pow(dif.y, 2) <= pow(radius, 2);
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

bool BB_Collision(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4) {
    if(v1->x <= v4->x && v2->x >= v3->x && v1->y <= v4->y && v2->y >= v3->y) {
        return true;
    } else {
        return false;
    }
}

bool BL_Collision(const Vector2* v1, const Vector2* v2, const Vector2* lv1, const Vector2* lv2) {
    if((v1->x <= lv1->x && lv1->x <= v2->x && v1->y >= lv1->y && lv1->y >= v2->y) ||
       (v1->x <= lv2->x && lv2->x <= v2->x && v1->y >= lv2->y && lv2->y >= v2->y)) {
        return true;
    }

    Vector2 upperRight = (v2->x, v1->y);
    Vector2 lowerLeft = (v1->x, v2->y);

    return LL_Collision(v1, v2, lv1, lv2) || LL_Collision(&lowerLeft, &upperRight, lv1, lv2);
}

bool LL_Collision(const Vector2* lv1, const Vector2* lv2, const Vector2* lv3, const Vector2* lv4) {
    double t1 = (lv3->x - lv4->x) * (lv1->y - lv3->y) + (lv3->y - lv4->y) * (lv3->x - lv1->x);
    double t2 = (lv3->x - lv4->x) * (lv2->y - lv3->y) + (lv3->y - lv4->y) * (lv3->x - lv2->x);
    double t3 = (lv1->x - lv2->x) * (lv3->y - lv1->y) + (lv1->y - lv2->y) * (lv1->x - lv3->x);
    double t4 = (lv1->x - lv2->x) * (lv4->y - lv1->y) + (lv1->y - lv2->y) * (lv1->x - lv4->x);

    return t1 * t2 < 0 && t3 * t4 < 0;
}