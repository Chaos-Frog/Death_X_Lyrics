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
        
        // 2��Collider�N���X����`�F�b�N
        bool CollisionCheck(const Collider* c1, const Collider* c2);

        bool CC_Collider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2);   // Circle & Circle
        bool BB_Collider(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4); // Box & Box
        bool CB_Collider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2);    // Circle & Box
        bool CL_Collider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2);  // Circle & Line
};

