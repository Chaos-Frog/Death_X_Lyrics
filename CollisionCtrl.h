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

        void Check_PBullet_Enemy_Collision();  // PlayerBulletとEnemy
        void Check_PBullet_Scraps_Collision(); // PlayerBulletとScraps
        bool Check_Player_Enemy_Collision();   // PlayerとEnemy
        bool Check_Player_EBullet_Collision(); // PlayerとEnemyBullet
        void Check_Player_Scraps_Collision();  // PlayerとScraps

    public:
        CollisionCtrl(GameController* gc);
        ~CollisionCtrl();
        void Update();
};

