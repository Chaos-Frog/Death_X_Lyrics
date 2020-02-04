#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "DxLib.h"
#include "Vector2.h"
#include "PlayerBullet.h"

#define SIZE_X 100
#define SIZE_Y 100
#define SPEED 4

class Player {
    private:
        Vector2* position;
        int playerImgs[12];
        int frame;
        int imgNum;
        int rotate;

        void Moving();
        void Shot();
    public:
        int bulletImage;
        std::vector<PlayerBullet*> bulletVec;

        Player();
        void Update();
};

