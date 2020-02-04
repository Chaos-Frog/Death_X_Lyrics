#include "GameController.h"
GameController::GameController() {
    player = new Player();
}

void GameController::Update() {
    DrawBox(320, 0, 960, 720, GetColor(200, 200, 200), TRUE);
    player->Update();
}