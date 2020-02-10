#pragma once
#include <vector>
#include "EnemyBullet.h"

class EnemyBulletsCtrl {
    private:
        Assets* assets;
    public:
        std::vector<EnemyBullet*> bulletsVec;

        EnemyBulletsCtrl(Assets* as);
        ~EnemyBulletsCtrl();
        void Update();
        void SetEnemyBullet(int type, Vector2* pos, double speed, double radAngle, double size);
};

