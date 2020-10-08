#pragma once
#include "DxLib.h"
#include "Assets.h"
class GameController;
class MainMenu;

enum Scenes {
    SCENE_MENU,
    SCENE_GAME
};

class SceneManager {
    private:
        static GameController* gameController;
        static MainMenu* mainMenu;
        static int currentScene;

    public:
        static bool Update();
        static void ChangeScene(int scene);
};

