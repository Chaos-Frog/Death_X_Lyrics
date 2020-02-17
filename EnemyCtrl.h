#pragma once
#include <vector>
#include <memory>
#include "Assets.h"
#include "Enemy001.h"

class EnemyCtrl {
    private:
        Assets* images;
        EnemyBulletsCtrl* EBC;
    public:
        std::vector<std::shared_ptr<Enemy>> enemysVec;

        EnemyCtrl(Assets* img, EnemyBulletsCtrl* ebc);
        ~EnemyCtrl();
        void Update();
        void SetEnemy(int type, Vector2* pos, int mp, int dp);
};

