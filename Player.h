#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <random>
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
        int bomberCT;

        void Moving();
        void Shot();
        void Bomber();
        void Draw();
    public:
        Vector2 position;
        Collider* collider;
        std::vector<PlayerBullet*> bulletVec;
        bool bomber;
        int hitCT;

        Player(Assets* img);
        ~Player();
        void Update();
        void DrawBullets();
        void HitFunc();
};

