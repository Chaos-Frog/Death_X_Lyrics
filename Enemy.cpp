#include "Enemy.h"
Enemy::Enemy(Vector2* pos, int mp, int dp) {
    position.x = pos->x;
    position.y = pos->y;
    movePatern = mp;
    danmakuPatern = dp;
    enemyType = 0;
}

void Enemy::Update() {}