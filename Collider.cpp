#include "Collider.h"

Collider::Collider(Vector2* pos, Vector2 relative) {
    centerPos = pos;
    relativePos = relative;
    position = *centerPos + relativePos;
}
Collider::~Collider(){}
void Collider::Update() {}
void Collider::DebugDraw() {}

Circle_C::Circle_C(Vector2* pos, Vector2 relative, double r) : Collider(pos, relative){
    type = CIRCLE;
    radius = r;
}

void Circle_C::Update() {
    position = *centerPos + relativePos;
}

void Circle_C::DebugDraw() {
    DrawCircle(round(position.x), round(position.y), radius, GetColor(0, 255, 0));
}


Box_C::Box_C(Vector2* pos, Vector2 relative, double xl, double yl) : Collider(pos, relative){
    type = BOX;
    xLength = xl;
    yLength = yl;

    pos1 = Vector2(position.x - (xl/2), position.y - (yl/2));
    pos2 = Vector2(position.x + (xl/2), position.y + (yl/2));
}

void Box_C::Update() {
    position = *centerPos + relativePos;
    pos1 = Vector2(position.x - (xLength/2), position.y - (yLength/2));
    pos2 = Vector2(position.x + (xLength/2), position.y + (yLength/2));
}

void Box_C::DebugDraw() {
    DrawBox(round(pos1.x), round(pos1.y), round(pos2.x), round(pos2.y), GetColor(0, 255, 0), TRUE);
}


Line_C::Line_C(Vector2* pos, Vector2 relative, double len, double degAngle) : Collider(pos, relative){
    type = LINE;
    length = len;
    angle = degAngle;

    double xp = (length/2) * cos(angle * (M_PI/180)) + position.x;
    double yp = (length/2) * sin(angle * (M_PI/180)) + position.y;
    pos1 = Vector2(xp, yp);
    pos2 = Vector2(-xp, -yp);
}

void Line_C::Update() {
    position = *centerPos + relativePos;
    double xp = (length/2) * cos(angle * (M_PI/180)) + position.x;
    double yp = (length/2) * sin(angle * (M_PI/180)) + position.y;
    pos1 = Vector2(xp, yp);
    pos2 = Vector2(-xp, -yp);
}

void Line_C::DebugDraw() {
    DrawLine(round(pos1.x), round(pos1.y), round(pos2.x), round(pos2.y), GetColor(0, 255, 0));
}