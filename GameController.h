#pragma once
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
        CollisionCtrl* colCtrl;

    public:
        GameController(Assets* img);
        ~GameController();
        void Update();
};

