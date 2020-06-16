#include "Enemy.h"
Enemy::Enemy(int type, Vector2* pos, int hp, int mp, int dp, Player* pla, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) {
    enemyType = type;
    position = *pos;
    HP = hp;
    invincible = false;
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

void Enemy::Update() {
    Moving();
    Danmaku();

    for(auto col : colliders) {
        col->Update();
    }

    frame++;
}

void Enemy::Moving() {}
void Enemy::Danmaku() {}
void Enemy::Draw() {}
void Enemy::DeathFunc() {}