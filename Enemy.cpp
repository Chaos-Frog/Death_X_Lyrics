#include "Enemy.h"
Enemy::Enemy(int type, Vector2* pos, int hp, int mp, int dp, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) {
    enemyType = type;
    position = *pos;
    HP = hp;
    movePatern = mp;
    danmakuPatern = dp;

    EBC = ebc;
    SC = sc;

    frame = 0;
}

void Enemy::Update() {}
void Enemy::DeathFunc() {}