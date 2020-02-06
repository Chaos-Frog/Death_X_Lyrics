#include "GameController.h"
GameController::GameController(Assets* img) {
    player = new Player(img);
    ec = new EnemyCtrl(img);
    colCtrl = new CollisionCtrl(player, ec);
    frame = 1;
}
GameController::~GameController() {
    delete player;
    delete ec;
    delete colCtrl;
}

void GameController::Update() {
    DrawBox(320, 0, 960, 720, GetColor(150, 150, 150), TRUE);
    
    player->Update();

    if(frame == 1) {
        ec->SetEnemy(1, new Vector2(640, 250), 0, 0);
    }
    ec->Update();

    colCtrl->Update();

    frame++;
}