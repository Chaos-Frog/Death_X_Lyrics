#pragma once
#include "Enemy_Air.h"

class Enemy001 : public Enemy_Air {
    private:
        ImageData* image;
        int imgNum;
        Vector2 first;
        double angle;

        void MovingAir() override;
        void Danmaku();

    public:
        Enemy001(Vector2* pos, int mp, int dp);
        void Draw() override;
        bool DeathFunc() override;
};

