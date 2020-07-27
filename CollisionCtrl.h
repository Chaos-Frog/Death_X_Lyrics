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

        void PBullet_Enemy();  // PlayerBullet‚ÆEnemy
        void PBullet_Scraps(); // PlayerBullet‚ÆScraps
        bool Player_Enemy();   // Player‚ÆEnemy
        bool Player_EBullet(); // Player‚ÆEnemyBullet
        void Player_Scraps();  // Player‚ÆScraps

    public:
        CollisionCtrl(GameController* gc);
        ~CollisionCtrl();
        void Update();
};

