#pragma once
#include "Enemy_Air.h"
class TestEnemy_Air : public Enemy_Air {
    private:
        Vector2 first;
        double angle;

        void MovingAir() override;
        void Danmaku();

        void Moving001();
        void Moving002();
        void Moving003();

    public:
        TestEnemy_Air(Vector2* pos, int mp, int dp);
        void Draw() override;
        bool DeathFunc() override;
};

