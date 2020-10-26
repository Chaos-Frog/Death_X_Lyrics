#include "EffectsController.h"
#include "GameController.h"

EffectsController::EffectsController(GameController* gc) {
    gameController = gc;
}
EffectsController::~EffectsController() {
    effectVec.clear();
}

void EffectsController::Update() {
    for(auto itr = effectVec.begin(); itr != effectVec.end();) {
        if((*itr)->Update()) itr++;
        else                 itr = effectVec.erase(itr);
    }
}

void EffectsController::Draw() {
    for(auto* itr : effectVec) {
        itr->Draw();
    }
}

void EffectsController::SetEffects(int num, Vector2 pos, Vector2 scale, int step, bool loop) {
    switch(num) {
        case 0:
            effectVec.push_back(new Effect_Explosion1(pos, scale, step, loop));
            break;
    }
}