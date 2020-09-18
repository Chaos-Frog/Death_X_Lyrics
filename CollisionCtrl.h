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

        void Check_PBullet_Enemy_Collision();  // PlayerBullet‚ÆEnemy
        void Check_PBullet_Scraps_Collision(); // PlayerBullet‚ÆScraps
        bool Check_Player_Enemy_Collision();   // Player‚ÆEnemy
        bool Check_Player_EBullet_Collision(); // Player‚ÆEnemyBullet
        void Check_Player_Scraps_Collision();  // Player‚ÆScraps

    public:
        CollisionCtrl(GameController* gc);
        ~CollisionCtrl();
        void Update();
};

