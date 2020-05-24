#pragma once
#include "DxLib.h"

class Assets {
    private:
    public:
        int player01[12];
        int player01_Hit[12];
        int playerBullet01;
        int playerMissile;
        int playerMissileExp[16];

        int enemy001[10];

        int enemyBullet01;
        int enemyBullet02;

        int scrap_S[6];

        Assets();
        ~Assets();
};