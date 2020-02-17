#pragma once
#include "PlayerBullet.h"
class P_Bullet : public PlayerBullet {
    private:
        int size;
    public:
        P_Bullet(Vector2* pos, double rad, Assets* img);
        bool MoveBullet();
        bool HitFunc();
};

