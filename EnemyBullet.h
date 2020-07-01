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
        int frame;
        double speed;
        double angle;
        double bulletSize;
    public:
        int bulletType;
        bool death;
        Vector2 position;
        Circle_C* collider;

        EnemyBullet(const Vector2 pos, double spd, double radA, double size, Assets* as);
        bool Update();
        virtual bool Moving();
        virtual void Draw();
        virtual bool DeathFunc();
};

class EBullet_01 : public EnemyBullet {
    public:
        EBullet_01(const Vector2 pos, double spd, double radA, double size, Assets* as);
        bool Moving() override;
        void Draw() override;
        bool DeathFunc() override;
};

class EBullet_02 : public EnemyBullet {
    public:
        EBullet_02(const Vector2 pos, double spd, double radA, double size, Assets* as);
        bool Moving() override;
        void Draw() override;
        bool DeathFunc() override;
};