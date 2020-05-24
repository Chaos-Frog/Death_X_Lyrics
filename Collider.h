#pragma once
#include "Vector2.h"

enum ColliderType {
    CIRCLE,
    BOX,
    LINE
};

class Collider {
    protected:
        int type;
        Vector2 centerPos;
};

class Circle_C : public Collider {
    public:
        Circle_C(Vector2* center, double r);
        double radius;
};

class Box_C : public Collider {
    public:
        Box_C(Vector2* center, double xl, double yl);
        Vector2 Pos1;
        Vector2 Pos2;
};

class Line_C : public Collider {
    public:
        Line_C(Vector2* center, double len, double degAngle);
        Vector2 Pos1;
        Vector2 Pos2;
};