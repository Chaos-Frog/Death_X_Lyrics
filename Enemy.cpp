#include "Enemy.h"
Enemy::Enemy(int type, Vector2* pos, int hp, int mp, int dp, Player* pla, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) {
    enemyType = type;
    position = *pos;
    HP = hp;
    movePatern = mp;
    danmakuPatern = dp;

    player = pla;
    EBC = ebc;
    SC = sc;

    frame = 0;
}

double Enemy::TargetPlayerAngle() {
    double a = atan2(player->position.x - position.x, player->position.y - position.y) * (180/M_PI);
    a = -a + 90.0f;
    return a;
}
void Enemy::Update() {}
void Enemy::DeathFunc() {}