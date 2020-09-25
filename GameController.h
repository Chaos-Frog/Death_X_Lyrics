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

/* �Q�[�������N���X */
class GameController {
    private:
    public:
        int frame;
        long score;
        int scrapMagni;
        int scrapMagniGage;
        Player* player;
        StageBase* stage;

        Assets* assets;
        EnemyCtrl* eneCtrl;
        EnemyBulletsCtrl* ebulCtrl;
        ScrapsCtrl* scrCtrl;
        CollisionCtrl* colCtrl;

        GameController(Assets* as);
        ~GameController();
        void Update();
        void Update_UI();
        void AddScore(int s, bool magni = true); // �X�R�A���Z(�{���L��)
};

