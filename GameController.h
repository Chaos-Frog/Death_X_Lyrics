#pragma once
#include <stdio.h>
#include <string>
#include <random>
#include "DxLib.h"
#include "Define.h"
#include "Assets.h"
#include "SceneManager.h"

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
        long score;
        int scrapMagni;
        int scrapMagniGage;
        
        StageBase* stage;
        Player* player;
        EnemyCtrl* eneCtrl;
        EnemyBulletsCtrl* ebulCtrl;
        ScrapsCtrl* scrCtrl;
        CollisionCtrl* colCtrl;

        GameController();
        ~GameController();
        void Update();
        void Update_UI();
        void AddScore(int s, bool magni = true); // スコア加算(倍率有無)
};

