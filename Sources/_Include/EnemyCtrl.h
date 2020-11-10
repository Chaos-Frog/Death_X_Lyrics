#pragma once
#include <vector>
#include "Player.h"
#include "Enemy_Air.h"
#include "Enemy_Ground.h"
#include "Enemy001.h"
#include "Enemy002.h"
#include "Enemy101.h"
#include "Boss_TEST.h"
class GameController;

class EnemyCtrl {
    private:
        EnemyCtrl();

    public:
        static std::vector<Enemy_Air*> enemysVec_Air;
        static std::vector<Enemy_Ground*> enemysVec_Ground;
        static Boss* boss;

        static void Init();

        static void Update();
        static void Draw();
        static void SetEnemy(int type, Vector2* pos, int mp, int dp);
        static void SetBoss(int stageNum);
};

