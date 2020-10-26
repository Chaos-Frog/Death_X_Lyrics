#pragma once
#include "DxLib.h"
#include "Effect.h"
#include "Effect_Explosion1.h"
#include <vector>
class GameController;

class EffectsController {
    private:
        GameController* gameController;

    public:
        std::vector<Effect*> effectVec;

        EffectsController(GameController* gc);
        ~EffectsController();
        void Update();
        void Draw();
        void SetEffects(int num, Vector2 pos, Vector2 scale, int step, bool loop);
};

