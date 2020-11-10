#include "EffectsCtrl.h"

std::vector<Effect*> EffectsCtrl::effectVec;

void EffectsCtrl::Init() {
    effectVec.clear();
}

void EffectsCtrl::Update() {
    for(auto itr = effectVec.begin(); itr != effectVec.end();) {
        if((*itr)->Update()) itr++;
        else                 itr = effectVec.erase(itr);
    }
}

void EffectsCtrl::Draw() {
    for(auto* itr : effectVec) {
        itr->Draw();
    }
}

void EffectsCtrl::SetEffects(int num, Vector2 pos, Vector2 scale, int step) {
    switch(num) {
        case 0:
            effectVec.push_back(new Effect_Explosion1(pos, scale, step));
            break;
    }
}