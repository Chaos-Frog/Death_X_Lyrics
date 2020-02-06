#pragma once
#include <vector>
#include "Assets.h"
#include "Enemy.h";
#include "Enemy001.h"

class EnemyCtrl {
    private:
    public:
        Assets* images;
        std::vector<Enemy*> enemysVec;

        EnemyCtrl(Assets* img);
        ~EnemyCtrl();
        void Update();
        void SetEnemy(int type, Vector2* pos, int mp, int dp);
};

