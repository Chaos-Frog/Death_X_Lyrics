#include "GameController.h"
GameController::GameController(Assets* img) {
    player = new Player(img);
    ebc = new EnemyBulletsCtrl(img);
    ec = new EnemyCtrl(img, ebc);
    colCtrl = new CollisionCtrl(player, ec);
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

    if(frame == 1) {
        ec->SetEnemy(1, new Vector2(640, 250), 0, 0);
    }
    
    player->Update();
    ec->Update();
    ebc->Update();

    colCtrl->Update();

    frame++;
}