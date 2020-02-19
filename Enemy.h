#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "DxLib.h"
#include "Vector2.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"

class Enemy {
    private:
    protected:
        int frame;
        int movePatern;
        int danmakuPatern;
        EnemyBulletsCtrl* EBC;
        ScrapsCtrl* SC;
    public:
        Vector2 position;
        int enemyType;
        int HP;

        Enemy(int type, Vector2* pos, int hp, int mp, int dp, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc);
        virtual void Update();
        virtual void DeathFunc();
};

