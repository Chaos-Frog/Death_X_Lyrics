#include "Boss.h"
#include "GameController.h"

Boss::Boss(GameController* gc) {
    HP = 0;
    frame = 0;
    phase = 0;
    score = 0;
    gameController = gc;
}
Boss::~Boss(){}

bool Boss::Update() { return false; }
void Boss::Draw(){}
bool Boss::DeathFunc() { return false; }

void Boss::CheckBossCollision() {
    CheckCol_Boss_PBullets();
    CheckCol_Boss_Player();
}
void Boss::CheckCol_Boss_PBullets(){}
void Boss::CheckCol_Boss_Player(){}