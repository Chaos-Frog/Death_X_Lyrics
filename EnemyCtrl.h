#pragma once
#include <vector>
#include "Player.h"
#include "Enemy_Air.h"
#include "Enemy_Ground.h"
#include "Enemy001.h"
#include "Enemy002.h"
class GameController;

class EnemyCtrl {
    private:
        Assets* images;
        GameController* gameCtrl;

    public:
        std::vector<Enemy_Air*> enemysVec_Air;
        std::vector<Enemy_Ground*> enemysVec_Ground;

        EnemyCtrl(Assets* img, GameController* gc);
        ~EnemyCtrl();
        void Update();
        void Draw();
        void SetEnemy(int type, Vector2* pos, int mp, int dp);
};

