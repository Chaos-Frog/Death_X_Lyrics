#pragma once
#include "Enemy.h"

class Enemy_Air : public Enemy {
    private:
    protected:
        bool Moving() override;
        virtual void MovingAir();
        bool CheckInArea() override;

    public:
        Enemy_Air(Enemys type, Vector2* pos, int mp, int dp);
};

