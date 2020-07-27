#include "Assets.h"

Assets::Assets() {
    LoadDivGraph("Assets/Player01.png", 12, 4, 3, 120, 100, player01);
    LoadDivGraph("Assets/Player01_Hit.png", 12, 4, 3, 120, 100, player01_Hit);
    playerBullet01 = LoadGraph("Assets/PlayerBullet.png");
    playerMissile = LoadGraph("Assets/Missile.png");
    LoadDivGraph("Assets/Exp01.png", 16, 4, 4, 100, 100, playerMissileExp);

    LoadDivGraph("Assets/E_001.png", 26, 4, 7, 64, 64, enemy001);
    LoadDivGraph("Assets/E_002.png", 26, 4, 7, 64, 64, enemy002);

    enemyBullet01 = LoadGraph("Assets/EB01.png");
    enemyBullet02 = LoadGraph("Assets/EB02.png");

    LoadDivGraph("Assets/Scrap_S.png", 6, 3, 2, 40, 40, scrap_S);
}


Assets::~Assets() {}