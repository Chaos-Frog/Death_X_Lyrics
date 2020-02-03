#pragma once
#include "DxLib.h"
#include "Player.h"

class GameController {
    private:
        Player* player;
    public:
        GameController();
        void Update();
};

