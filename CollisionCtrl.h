#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "Vector2.h"
#include "Player.h"
#include "EnemyCtrl.h"

class CollisionCtrl {
    private:
        Player* player;
        EnemyCtrl* enemyCtrl;
    public:
        CollisionCtrl(Player* pl, EnemyCtrl* ec);
        ~CollisionCtrl();
        void Update();
        bool CC_Colider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2);
        bool CB_Colider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2);
        bool CL_Colider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2);
};

