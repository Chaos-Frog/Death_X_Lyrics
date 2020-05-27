#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "Define.h"
#include "Vector2.h"
#include "Collider.h"
#include "Player.h"
#include "EnemyCtrl.h"
#include "ScrapsCtrl.h"

class GameController;

class CollisionCtrl {
    private:
        GameController* gameCtrl;
        Player* player;
        EnemyCtrl* enemyCtrl;
        EnemyBulletsCtrl* EBC;
        ScrapsCtrl* scrapsCtrl;

    public:
        CollisionCtrl(GameController* gc, Player* pl, EnemyCtrl* ec, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc);
        ~CollisionCtrl();
        void Update();
        bool CollisionCheck(const Collider* c1, const Collider* c2);
        bool CC_Collider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2);
        bool BB_Collider(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4);
        bool CB_Collider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2);
        bool CL_Collider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2);
};

