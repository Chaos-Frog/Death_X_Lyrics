#pragma once
#include "Enemy_Air.h"

#define X_SIZE 64
#define Y_SIZE 64
#define LOOP 2

class Enemy002 : public Enemy_Air {
    private:
        int* image;
        int imgNum;
        Vector2 first;
        double angle;
        Vector2 shotPos[2] = {Vector2(20, 0), Vector2(-20, 0)};

        void Moving() override;
        void Danmaku() override;
    
    public:
        Enemy002(Vector2* pos, int mp, int dp, int* img, GameController* gc);
        void Draw() override;
        bool DeathFunc() override;
};