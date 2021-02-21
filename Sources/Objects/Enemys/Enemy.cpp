#include "Enemy.h"
#include "GameController.h"

Enemy::Enemy(Enemys type, Vector2* pos, int mp, int dp, bool onG) {
    enemyType     = static_cast<int>(type);
    position      = *pos;
    HP            = Assets::enemyParams[enemyType].hp;
    score         = Assets::enemyParams[enemyType].score;

    movePatern    = mp;
    danmakuPatern = dp;
    invincible    = false;
    withdrawal    = false;
    onGround      = onG;

    frame = 0;
}

double Enemy::TargetPlayerAngle() {
    double a = atan2(GameController::player->position.x - position.x, GameController::player->position.y - position.y) * (180/M_PI);
    a = -a + 90.0f;
    return a;
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
        GameController::AddScore(score, true);
    }
}

bool Enemy::CheckInArea() { return false; }
bool Enemy::Moving() { return false; }
void Enemy::Danmaku(){}
void Enemy::Draw(){}
bool Enemy::DeathFunc() { return false; }