#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "DxLib.h"
#include "Vector2.h"
#include "Collider.h"
#include "Player.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"

class Enemy {
    private:
    protected:
        int frame;
        int movePatern;
        int danmakuPatern;
        Player* player;
        EnemyBulletsCtrl* EBC;
        ScrapsCtrl* SC;

        double TargetPlayerAngle();
    public:
        Vector2 position;
        std::vector<Collider*> colliders;
        int enemyType;
        int HP;

        Enemy(int type, Vector2* pos, int hp, int mp, int dp, Player* pla, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc);
        virtual void Update();
        virtual void DeathFunc();
};

