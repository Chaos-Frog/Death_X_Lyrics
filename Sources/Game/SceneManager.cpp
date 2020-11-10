#include "SceneManager.h"
#include "GameController.h"
#include "MainMenu.h"

extern int screenGame;
extern int screenFull;

int SceneManager::currentScene = SCENE_MENU;
MainMenu* SceneManager::mainMenu;

void SceneManager::Init() {
    mainMenu       = new MainMenu();
    GameController::Init();
}

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
            GameController::Update();

            SetDrawScreen(screenFull);
            ClearDrawScreen();
            GameController::Update_UI();
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
            GameController::Init();
            break;

        default:
            break;
    }
}