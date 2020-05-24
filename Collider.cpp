#include "Collider.h"

Circle_C::Circle_C(Vector2* center, double r) {
    type = CIRCLE;
    centerPos = *center;
    radius = r;
}

Box_C::Box_C(Vector2* center, double xl, double yl) {
    type = BOX;
    centerPos = *center;
    Pos1 = Vector2(centerPos.x - (xl / 2), centerPos.y - (yl / 2));
    Pos2 = Vector2(centerPos.x + (xl / 2), centerPos.y + (yl / 2));
}

Line_C::Line_C(Vector2* center, double len, double degAngle) {
    type = LINE;
    centerPos = *center;
}