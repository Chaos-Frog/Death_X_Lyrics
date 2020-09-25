#pragma once
#include "Enemy.h"
class Enemy_Air : public Enemy {
    private:
    protected:
        bool Moving() override;
        virtual void MovingAir();
        bool CheckInArea() override;

    public:
        Enemy_Air(int type, Vector2* pos, int hp, int s, int mp, int dp, GameController* gc);
};

