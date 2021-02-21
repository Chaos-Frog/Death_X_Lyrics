#pragma once
#include "Enemy.h"

class Enemy_Ground : public Enemy {
    private:
    protected:
        Vector2* stageGroundPos;
        Vector2 groundPos;

        bool Moving() override;
        virtual void MovingGround();
        bool CheckInArea() override;

    public:
        Enemy_Ground(Enemys type, Vector2* pos, int mp, int dp);
};

