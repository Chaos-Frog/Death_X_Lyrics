#pragma once
#include <vector>
#include "DxLib.h"
#include "Vector2.h"
#include "Enemy.h";
#include "Enemy001.h"

class EnemyCtrl {
    private:
    public:
        std::vector<Enemy*> enemysVec;
        
        void Update();
        void SetEnemy(int type, Vector2* pos);
};

