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

        void PBullet_Enemy();  // PlayerBullet��Enemy
        void PBullet_Scraps(); // PlayerBullet��Scraps
        bool Player_Enemy();   // Player��Enemy
        bool Player_EBullet(); // Player��EnemyBullet
        void Player_Scraps();  // Player��Scraps

    public:
        CollisionCtrl(GameController* gc);
        ~CollisionCtrl();
        void Update();
};

