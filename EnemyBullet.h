#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"

class EnemyBullet {
    protected:
        int* image;
        double speed;
        double angle;
        double bulletSize;
    public:
        int bulletType;
        Vector2 position;
        Circle_C* collider;
        double radius;

        EnemyBullet(Vector2* pos, double spd, double radA, double size, Assets* as);
        virtual bool Moving();
        virtual void Draw();
};

class EBullet_01 : public EnemyBullet {
    public:
        EBullet_01(Vector2* pos, double spd, double radA, double size, Assets* as);
        bool Moving();
        void Draw();
};

class EBullet_02 : public EnemyBullet {
    public:
        EBullet_02(Vector2* pos, double spd, double radA, double size, Assets* as);
        bool Moving();
        void Draw();
};