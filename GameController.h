#pragma once
#include <stdio.h>
#include <string>
#include "Assets.h"
#include "Define.h"
#include "Player_A.h"
#include "EnemyCtrl.h"
#include "CollisionCtrl.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"

class GameController {
    private:
    public:
        int frame;
        int score;
        int scrapMagni;
        int scrapMagniGage;
        Player* player;
        EnemyCtrl* eneCtrl;
        EnemyBulletsCtrl* ebulCtrl;
        ScrapsCtrl* scrCtrl;
        CollisionCtrl* colCtrl;

        GameController(Assets* img);
        ~GameController();
        void Update();
        void Update_UI();
        void AddScore(int s, bool magni = true); // ÉXÉRÉAâ¡éZ(î{ó¶óLñ≥)
};

