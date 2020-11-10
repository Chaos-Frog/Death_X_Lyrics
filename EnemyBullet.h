#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"
#include "Easing.h"

class EnemyBullet {
    protected:
        ImageData* image;
        int frame;
        double speed;
        double angle;
        double bulletSize;

    public:
        int bulletType;
        bool death;
        Vector2 position;
        Collider* collider;

        EnemyBullet(ImageData* id, Collider* col, Vector2 pos, int bt, double spd, double radA, double size);
        bool Update();
        virtual bool Moving();
        virtual void Draw();
        virtual bool DeathFunc();
        bool CheckInArea();
};

class EBullet_01 : public EnemyBullet {
    private:
    public:
        EBullet_01(Vector2 pos, double spd, double radA, double size);
        bool Moving() override;
        void Draw() override;
        bool DeathFunc() override;
};

class EBullet_02 : public EnemyBullet {
    private:
    public:
        EBullet_02(Vector2 pos, double spd, double radA, double size);
        bool Moving() override;
        void Draw() override;
        bool DeathFunc() override;
};