#include "Assets.h"
Assets::Assets() {
    LoadDivGraph("Assets/Heli.png", 12, 4, 3, 100, 100, player01);

    playerBullet01 = LoadGraph("Assets/PlayerBullet.png");

    LoadDivGraph("Assets/TestEnemy.png", 8, 4, 2, 64, 64, enemy001);
}


Assets::~Assets() {}