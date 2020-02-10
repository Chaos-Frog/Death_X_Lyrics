#include "Enemy.h"
Enemy::Enemy(int type, Vector2* pos, int hp, int mp, int dp, EnemyBulletsCtrl* ebc) {
    enemyType = type;
    position = *pos;
    HP = hp;
    movePatern = mp;
    danmakuPatern = dp;
    EBC = ebc;
    frame = 1;
}

void Enemy::Update() {}