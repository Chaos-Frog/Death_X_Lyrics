#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"

class EnemyBullet {
    private:
        int* image;
        double speed;
        double angle;
        double bulletSize;
    public:
        int bulletType;
        Vector2 position;

        EnemyBullet(int type, Vector2* pos, double spd, double radA, double size, Assets* as);
        bool Moving();
};

