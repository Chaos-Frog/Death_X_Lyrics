#pragma once
#include <cmath>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"

class PlayerBullet {
    private:
    protected:
        int frame;
        double angle;
        double velocity;
        bool hitted;
        Assets* imgs;

    public:
        int bulletType;
        double cr;
        Vector2 position;
        Collider* collider;

        PlayerBullet(int type, Vector2* pos, double rad, Assets* img);
        ~PlayerBullet();
        virtual bool MoveBullet();
        virtual void Draw();
        virtual bool HitFunc();
};

class P_Bullet : public PlayerBullet {
    private:
        int size;

    public:
        P_Bullet(Vector2* pos, double rad, Assets* img);
        bool MoveBullet();
        void Draw();
        bool HitFunc();
};

class P_Missile : public PlayerBullet {
    private:
        int size;

    public:
        P_Missile(Vector2* pos, double rad, Assets* img);
        bool MoveBullet();
        void Draw();
        bool HitFunc();
};