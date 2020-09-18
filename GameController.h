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
#include "Stage_1.h"

/* ゲーム処理クラス */
class GameController {
    private:
    public:
        int frame;
        int score;
        int scrapMagni;
        int scrapMagniGage;
        Player* player;
        StageBase* stage;

        EnemyCtrl* eneCtrl;
        EnemyBulletsCtrl* ebulCtrl;
        ScrapsCtrl* scrCtrl;
        CollisionCtrl* colCtrl;

        GameController(Assets* img);
        ~GameController();
        void Update();
        void Update_UI();
        void AddScore(int s, bool magni = true); // スコア加算(倍率有無)
};

