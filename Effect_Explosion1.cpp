#include "Effect_Explosion1.h"

Effect_Explosion1::Effect_Explosion1(Vector2 pos, Vector2 scl, int step, bool lp)
                  :Effect(Assets::playerMissileExp.handle, step, lp, pos, Vector2(100, 100), scl) {
    imageNum = Assets::playerMissileExp.imageNum;
}
Effect_Explosion1::~Effect_Explosion1(){}

bool Effect_Explosion1::Update() {
    if(Effect::Update()) {
        position.y -= 2.0;
        return true;
    } else {
        return false;
    }
}