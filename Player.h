#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <memory>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "P_Bullet.h"
#include "P_Missile.h"

#define SIZE_X 100
#define SIZE_Y 100
#define SPEED 4

class Player {
    private:
        Assets* imgs;
        int* playerImgs;
        int* playerImgs_ADD;
        int frame;
        int imgNum;
        int rotate;
        int shotCT;
        int missileCT;

        void Moving();
        void Shot();
        void Draw();
    public:
        Vector2 position;
        std::vector<std::shared_ptr<PlayerBullet>> bulletVec;
        int hitCT;

        Player(Assets* img);
        ~Player();
        void Update();
};

