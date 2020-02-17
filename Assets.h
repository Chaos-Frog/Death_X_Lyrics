#pragma once
#include "DxLib.h"

class Assets {
    private:
    public:
        int player01[12];
        int player01_ADD[12];
        int playerBullet01;
        int playerMissile;
        int playerMissileExp[16];

        int enemy001[8];

        int enemyBullet01;
        int enemyBullet02;

        Assets();
        ~Assets();
};