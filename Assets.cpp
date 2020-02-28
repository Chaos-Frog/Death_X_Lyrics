#include "Assets.h"
Assets::Assets() {
    LoadDivGraph("Assets/Heli.png", 12, 4, 3, 100, 100, player01);
    LoadDivGraph("Assets/Heli_ADD.png", 12, 4, 3, 100, 100, player01_ADD);
    playerBullet01 = LoadGraph("Assets/PlayerBullet.png");
    playerMissile = LoadGraph("Assets/Missile.png");
    LoadDivGraph("Assets/Exp01.png", 16, 4, 4, 100, 100, playerMissileExp);

    LoadDivGraph("Assets/TestEnemy.png", 10, 5, 2, 64, 64, enemy001);

    enemyBullet01 = LoadGraph("Assets/EB01.png");
    enemyBullet02 = LoadGraph("Assets/EB02.png");

    LoadDivGraph("Assets/Scrap_S.png", 6, 3, 2, 40, 40, scrap_S);
}


Assets::~Assets() {}