#pragma once
#include "DxLib.h"
#include "Assets.h"
#include "Player.h"
#include "EnemyCtrl.h"
#include "CollisionCtrl.h"

class GameController {
    private:
        int frame;
        Player* player;
        EnemyCtrl* ec;
        CollisionCtrl* colCtrl;

    public:
        GameController(Assets* img);
        ~GameController();
        void Update();
};

