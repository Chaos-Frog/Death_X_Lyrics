#pragma once
#include "Enemy.h"
class Enemy001 : public Enemy {
    private:
        void Moving();
        void Danmaku();
    public:
        int HP;

        Enemy001(Vector2* pos, int mp, int dp);
        void Update();
};

