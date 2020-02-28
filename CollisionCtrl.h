#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>
#include "Define.h"
#include "Vector2.h"
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
        bool CC_Colider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2);
        bool CB_Colider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2);
        bool CL_Colider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2);
};

