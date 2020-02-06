#pragma once
#include "Enemy.h"

#define X_SIZE 64
#define Y_SIZE 64
#define IMAGE_NUM 8


class Enemy001 : public Enemy {
    private:
        int* image;
        int imgNum;

        void Moving();
        void Danmaku();
        void Draw();
    public:
        Enemy001(Vector2* pos, int mp, int dp, int* img);
        void Update();
};
