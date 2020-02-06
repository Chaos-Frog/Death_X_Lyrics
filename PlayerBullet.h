#pragma once
#include <cmath>
#include "DxLib.h"
#include "Vector2.h"

class PlayerBullet {
    private:
        int bulletType;
        int *bulletImg;
        double angle;
    public:
        Vector2 position;

        PlayerBullet(int type, Vector2* pos, double rad, int* img);
        ~PlayerBullet();
        bool MoveBullet();
};

