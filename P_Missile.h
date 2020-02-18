#pragma once
#include "PlayerBullet.h"
class P_Missile : public PlayerBullet {
    private:
        int size;
        bool hitted;
    public:
        P_Missile(Vector2* pos, double rad, Assets* img);
        bool MoveBullet();
        bool HitFunc();
};
