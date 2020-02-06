#include "Enemy.h"
Enemy::Enemy(int type, Vector2* pos, int hp, int mp, int dp) {
    enemyType = type;
    position.x = pos->x;
    position.y = pos->y;
    HP = hp;
    movePatern = mp;
    danmakuPatern = dp;
    frame = 1;
}

void Enemy::Update() {}