#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "DxLib.h"
#include "Vector2.h"
#include "Collider.h"
class GameController;

class Enemy {
    private:
    protected:
        int frame;
        int movePatern;
        int danmakuPatern;
        GameController* gameCtrl;

        double TargetPlayerAngle();
        void SetEnemyBullet(int type, const Vector2 pos, double speed, double degAngle, double size);
        void SetScrap(int type, int num, Vector2* pos);
        virtual void Moving();
        virtual void Danmaku();

    public:
        Vector2 position;
        std::vector<Collider*> colliders;
        int enemyType;
        bool invincible;
        bool onGround;
        int HP;
        int score;

        Enemy(int type, Vector2* pos, int hp, int s, int mp, int dp, bool onG, GameController* gc);
        bool Update();
        void Damage(int dmg);
        virtual void Draw();
        virtual bool DeathFunc();
};

