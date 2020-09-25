#pragma once
#include "Enemy_Air.h"

#define E2_X_SIZE 64
#define E2_Y_SIZE 64
#define E2_LOOP 2

class Enemy002 : public Enemy_Air {
    private:
        int* image;
        int imgNum;
        Vector2 first;
        double angle;
        Vector2 shotPos[2] = {Vector2(20, 0), Vector2(-20, 0)};

        void MovingAir() override;
        void Danmaku() override;
    
    public:
        Enemy002(Vector2* pos, int mp, int dp, GameController* gc);
        void Draw() override;
        bool DeathFunc() override;
};