#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "Define.h"
#include "Vector2.h"
#include "Player.h"
#include "EnemyCtrl.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"
class GameController;

class CollisionCtrl {
    private:
        GameController* gameCtrl;
        Player* player;
        EnemyCtrl* enemyCtrl;
        EnemyBulletsCtrl* eBulletsCtrl;
        ScrapsCtrl* scrapsCtrl;

        void PBullet_Enemy();  // PlayerBulletとEnemy
        void PBullet_Scraps(); // PlayerBulletとScraps
        bool Player_Enemy();   // PlayerとEnemy
        bool Player_EBullet(); // PlayerとEnemyBullet
        void Player_Scraps();  // PlayerとScraps

    public:
        CollisionCtrl(GameController* gc);
        ~CollisionCtrl();
        void Update();
};

