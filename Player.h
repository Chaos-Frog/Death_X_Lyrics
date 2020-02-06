#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "DxLib.h"
#include "Assets.h"
#include "Vector2.h"
#include "PlayerBullet.h"

#define SIZE_X 100
#define SIZE_Y 100
#define SPEED 4

class Player {
    private:
        Assets* imgs;
        Vector2* position;
        int* playerImgs;
        int frame;
        int imgNum;
        int rotate;
        int shotCT;

        void Moving();
        void Shot();
    public:
        std::vector<PlayerBullet*> bulletVec;

        Player(Assets* img);
        ~Player();
        void Update();
};

