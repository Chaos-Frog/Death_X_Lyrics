#include "Enemy_Air.h"
#include "GameController.h"
Enemy_Air::Enemy_Air(int type, Vector2* pos, int hp, int s, int mp, int dp, GameController* gc) : Enemy(type, pos, hp, s, mp, dp, false, gc){}
