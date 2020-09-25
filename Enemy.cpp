#include "Enemy.h"
#include "GameController.h"
Enemy::Enemy(int type, Vector2* pos, int hp, int s, int mp, int dp, bool onG, GameController* gc) {
    enemyType     = type;
    position      = *pos;
    HP            = hp;
    score         = s;
    movePatern    = mp;
    danmakuPatern = dp;
    invincible    = false;
    withdrawal    = false;
    onGround      = onG;

    gameCtrl = gc;

    frame = 0;
}

double Enemy::TargetPlayerAngle() {
    double a = atan2(gameCtrl->player->position.x - position.x, gameCtrl->player->position.y - position.y) * (180/M_PI);
    a = -a + 90.0f;
    return a;
}

void Enemy::SetEnemyBullet(int type, const Vector2 pos, double speed, double degAngle, double size) {
    gameCtrl->ebulCtrl->SetEnemyBullet(type, pos, speed, degAngle, size);
}

void Enemy::SetScrap(int type, int num, Vector2* pos) {
    for(int i=0; i < num; i++) {
        gameCtrl->scrCtrl->SetScrap(type, pos);
    }
}

bool Enemy::Update() {
    if(HP > 0) {
        if(!Moving()) {
            return false;
        }
        Danmaku();
        for(auto col : colliders) {
            col->Update();
        }
    } else {
        return DeathFunc();
    }

    frame++;
    return true;
}

void Enemy::Damage(int dmg) {
    HP -= dmg;
    if(HP <= 0) {
        frame = 0;
        gameCtrl->AddScore(score);
    }
}

bool Enemy::CheckInArea() { return false; }
bool Enemy::Moving() { return false; }
void Enemy::Danmaku(){}
void Enemy::Draw(){}
bool Enemy::DeathFunc() { return false; }