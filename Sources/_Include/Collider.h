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

struct ColliderParam {
    int type;
    Vector2 centerPos;
    Vector2 pos1, pos2;
    double radius;
};

class Collider {
    protected:
        Vector2* basePos;
        Vector2 relativePos;
        ColliderParam parameter;

    public:
        Collider(Vector2* pos, Vector2 relative);
        ~Collider();
        virtual void Update();
        ColliderParam GetParameter() const;
};

class Circle_C : public Collider {
    public:
        Circle_C(Vector2* pos, Vector2 relative, double r);
        void Update();
};

class Box_C : public Collider {
    private:
        double xLength, yLength;

    public:
        Box_C(Vector2* pos, Vector2 relative, double xl, double yl);
        void Update();
};

class Line_C : public Collider {
    private:
        double length, angle;
    
    public:
        Line_C(Vector2* pos, Vector2 relative, double len, double degAngle);
        void Update();
};


bool CheckCollision(const Collider* c1, const Collider* c2);                                       // 2つのCollider判定チェック
bool CC_Collision(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2);       // Circle & 
bool CB_Collision(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2);        // Circle & Box
bool CL_Collision(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2);      // Circle & Line
bool BB_Collision(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4);     // Box    & Box
bool BL_Collision(const Vector2* v1, const Vector2* v2, const Vector2* lv1, const Vector2* lv2);   // Box    & Line
bool LL_Collision(const Vector2* lv1, const Vector2* lv2, const Vector2* lv3, const Vector2* lv4); // Line   & Line