#pragma once
#include "Effect.h"

class Effect_Explosion1 : public Effect{
    private:
    public:
        Effect_Explosion1(Vector2 pos, Vector2 scl, int step);
        ~Effect_Explosion1();

        bool Update() override;
};

