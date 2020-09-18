#include "Enemy_Ground.h"
#include "GameController.h"
Enemy_Ground::Enemy_Ground(int type, Vector2* pos, int hp, int s, int mp, int dp, GameController* gc) : Enemy(type, pos, hp, s, mp, dp, true, gc) {
    groundPos = &(gameCtrl->stage->groundPos);
}