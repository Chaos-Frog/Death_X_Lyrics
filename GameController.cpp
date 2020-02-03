#include "GameController.h"
GameController::GameController() {
    player = new Player();
}

void GameController::Update() {
    DrawBox(180, 0, 780, 720, GetColor(200, 200, 200), TRUE);
    player->Update();
}