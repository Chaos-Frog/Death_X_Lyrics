#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Assets.h"
#include "Vector2.h"

enum ColliderType {
    CIRCLE,
    BOX,
    LINE
};

class Collider {
    protected:
        Vector2* centerPos;
        Vector2 relativePos;
    public:
        int type;
        Vector2 position;
        double radius;
        Vector2 pos1;
        Vector2 pos2;

        Collider(Vector2* pos, Vector2 relative);
        virtual ~Collider();
        virtual void Update();
        virtual void DebugDraw();
};

class Circle_C : public Collider {
    public:
        Circle_C(Vector2* pos, Vector2 relative, double r);
        void Update();
        void DebugDraw();
};

class Box_C : public Collider {
    private:
        double xLength, yLength;

    public:
        Box_C(Vector2* pos, Vector2 relative, double xl, double yl);
        void Update();
        void DebugDraw();
};

class Line_C : public Collider {
    private:
        double length, angle;
    
    public:
        Line_C(Vector2* pos, Vector2 relative, double len, double degAngle);
        void Update();
        void DebugDraw();
};