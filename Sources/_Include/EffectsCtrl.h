#pragma once
#include "DxLib.h"
#include "Effect.h"
#include "Effect_Explosion1.h"
#include <vector>

class EffectsCtrl {
    private:
        EffectsCtrl();

    public:
        static std::vector<Effect*> effectVec;

        static void Init();

        static void Update();
        static void Draw();
        static void SetEffects(int num, Vector2 pos, Vector2 scale, int step);
};

