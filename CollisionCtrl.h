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
        
        // 2つのColliderクラス判定チェック
        bool CollisionCheck(const Collider* c1, const Collider* c2);

        bool CC_Collider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2);   // Circle & Circle
        bool BB_Collider(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4); // Box & Box
        bool CB_Collider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2);    // Circle & Box
        bool CL_Collider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2);  // Circle & Line
};

