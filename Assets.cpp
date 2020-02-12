#include "Assets.h"
Assets::Assets() {
    LoadDivGraph("Assets/Heli.png", 12, 4, 3, 100, 100, player01);
    LoadDivGraph("Assets/Heli_ADD.png", 12, 4, 3, 100, 100, player01_ADD);
    playerBullet01 = LoadGraph("Assets/PlayerBullet.png");
    LoadDivGraph("Assets/TestEnemy.png", 8, 4, 2, 64, 64, enemy001);
    enemyBullet01 = LoadGraph("Assets/EB01.png");
    enemyBullet02 = LoadGraph("Assets/EB02.png");
}


Assets::~Assets() {}