#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"
#include "PlayerBullet.h"

#define SIZE_X 120
#define SIZE_Y 100
#define SPEED 4

class Player {
    private:
        Assets* imgs;
        int* playerImgs;
        int* playerImgs_Hit;
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
        Collider* collider;
        std::vector<PlayerBullet*> bulletVec;
        int hitCT;

        Player(Assets* img);
        ~Player();
        void Update();
        void DrawBullets();
};

