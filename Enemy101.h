#pragma once
#include "Enemy_Ground.h"

#define E101_X_SIZE 30
#define E101_Y_SIZE 60

class Enemy101 : public Enemy_Ground {
    private:
        Vector2 first;
        double angle;

        void MovingGround() override;
        void Danmaku() override;
    
    public:
        Enemy101(Vector2* pos, int mp, int dp, GameController* gc);
        void Draw() override;
        bool DeathFunc() override;
};

