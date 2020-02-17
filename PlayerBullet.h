#pragma once
#include <cmath>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"

class PlayerBullet {
    private:
    protected:
        int frame;
        double angle;
        double velocity;
        Assets* imgs;
    public:
        int bulletType;
        double cr;
        Vector2 position;

        PlayerBullet(int type, Vector2* pos, double rad, Assets* img);
        ~PlayerBullet();
        virtual bool MoveBullet();
        virtual bool HitFunc();
};

