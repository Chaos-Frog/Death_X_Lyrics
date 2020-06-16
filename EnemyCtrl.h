#pragma once
#include <vector>
#include "Player.h"
#include "Enemy001.h"
#include "Enemy002.h"

class EnemyCtrl {
    private:
        Assets* images;
        Player* player;
        EnemyBulletsCtrl* EBC;
        ScrapsCtrl* SC;

    public:
        std::vector<Enemy*> enemysVec;

        EnemyCtrl(Assets* img, Player* pl, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc);
        ~EnemyCtrl();
        void Update();
        void Draw();
        void SetEnemy(int type, Vector2* pos, int mp, int dp);
};

