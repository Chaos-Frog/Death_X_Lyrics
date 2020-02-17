#include "GameController.h"
#include <random>
GameController::GameController(Assets* img) {
    player = new Player(img);
    ebc = new EnemyBulletsCtrl(img);
    ec = new EnemyCtrl(img, ebc);
    colCtrl = new CollisionCtrl(player, ec, ebc);
    frame = 1;
}
GameController::~GameController() {
    delete player;
    delete ec;
    delete ebc;
    delete colCtrl;
}

void GameController::Update() {
    DrawBox(320, 0, 960, 720, GetColor(150, 150, 150), TRUE);

    if(frame == 1 || ec->enemysVec.size() <= 0) {
        std::random_device rnd;
        std::mt19937 mt(rnd());
        std::uniform_int_distribution<int> rndX(340, 940);
        ec->SetEnemy(1, new Vector2(rndX(mt), -100), 2, 0);
    }
    
    player->Update();
    ec->Update();
    ebc->Update();

    if(frame%2 == 0) colCtrl->Update();

    DrawBox(0, 0, 320, 720, GetColor(50, 50, 50), TRUE);
    DrawBox(960, 0, 1280, 720, GetColor(50, 50, 50), TRUE);
    frame++;

    // Debug //
    int bnum = ebc->bulletsVec.size();
    std::string str = "BulletsNum:" + std::to_string(bnum);
    SetFontSize(20);
    DrawString(10, 10, str.c_str(), GetColor(0, 200, 0));
}