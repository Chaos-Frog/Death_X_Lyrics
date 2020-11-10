#pragma once
#include "Enemy_Ground.h"

class Enemy101 : public Enemy_Ground {
    private:
        Vector2 first;
        double angle;

        void MovingGround() override;
        void Danmaku() override;
    
    public:
        Enemy101(Vector2* pos, int mp, int dp);
        void Draw() override;
        bool DeathFunc() override;
};

