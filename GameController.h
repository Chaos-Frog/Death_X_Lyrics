#pragma once
#include <stdio.h>
#include <string>
#include "Assets.h"
#include "Define.h"
#include "Player.h"
#include "EnemyCtrl.h"
#include "CollisionCtrl.h"
#include "EnemyBulletsCtrl.h"

class GameController {
    private:
        int frame;
        Player* player;
        EnemyCtrl* ec;
        EnemyBulletsCtrl* ebc;
        ScrapsCtrl* sc;
        CollisionCtrl* colCtrl;

    public:
        int score;
        int scrapMagni;
        int scrapMagniGage;
        GameController(Assets* img);
        ~GameController();
        void Update();
        void Update_UI();
};

