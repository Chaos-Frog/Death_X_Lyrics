#pragma once
#include "Enemy.h"

#define X_SIZE 64
#define Y_SIZE 64
#define LOOP 2

class Enemy001 : public Enemy {
    private:
        int* image;
        int imgNum;
        Vector2 first;
        double angle;

        void Moving();
        void Danmaku();

    public:
        Enemy001(Vector2* pos, int mp, int dp, int* img, GameController* gc);
        void Draw() override;
        bool DeathFunc() override;
};

