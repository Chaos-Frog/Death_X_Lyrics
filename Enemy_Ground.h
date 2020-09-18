#pragma once
#include "Enemy.h"
class Enemy_Ground : public Enemy {
    private:
    protected:
        Vector2* groundPos;
    public:
        Enemy_Ground(int type, Vector2* pos, int hp, int s, int mp, int dp, GameController* gc);
};

