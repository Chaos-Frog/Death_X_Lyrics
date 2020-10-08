#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "EnemyBullet.h"

class EnemyBulletsCtrl {
    private:
    public:
        std::vector<EnemyBullet*> bulletsVec;

        EnemyBulletsCtrl();
        ~EnemyBulletsCtrl();
        void Update();
        void Draw();
        void SetEnemyBullet(int type, const Vector2 pos, double speed, double radAngle, double size);
        void DeleteAllBullet();
};