#include "SceneManager.h"
#include "GameController.h"
#include "MainMenu.h"

extern int screenGame;
extern int screenFull;

MainMenu* SceneManager::mainMenu             = new MainMenu();
GameController* SceneManager::gameController = new GameController();

bool SceneManager::Update() {
    switch(currentScene) {
        case SCENE_MENU:
            SetDrawScreen(screenFull);
            ClearDrawScreen();
            if(!mainMenu->Update()) return false;
            break;

        case SCENE_GAME:
            SetDrawScreen(screenGame);
            ClearDrawScreen();
            gameController->Update();

            SetDrawScreen(screenFull);
            ClearDrawScreen();
            gameController->Update_UI();
            DrawExtendGraph(320, 0, 960, 720, screenGame, TRUE);
            break;

        default:
            break;
    }
    return true;
}

void SceneManager::ChangeScene(int scene) {
    currentScene = scene;

    switch(scene) {
        case SCENE_MENU:
            mainMenu = new MainMenu();
            break;

        case SCENE_GAME:
            gameController = new GameController();
            break;

        default:
            break;
    }
}