#pragma once
#include "Enemy_Ground.h"
class Enemy101 : public Enemy_Ground {
    private:
    public:
        Enemy101(Vector2* pos, int mp, int dp, int* img, GameController* gc);
        void Draw() override;
        bool DeathFunc() override;
};

