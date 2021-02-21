#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "EnemyBullet.h"

class EnemyBulletsCtrl {
    private:
        EnemyBulletsCtrl();

    public:
        static std::vector<EnemyBullet*> bulletsVec;

        static void Init();

        static void Update();
        static void Draw();
        static void SetEnemyBullet(int type, const Vector2 pos, double speed, double degAngle, double size);
        static void DeleteAllBullet();
};