#pragma once
#include "DxLib.h"
#include "Assets.h"
class MainMenu;

enum Scenes {
    SCENE_MENU,
    SCENE_GAME
};

class SceneManager {
    private:
        static MainMenu* mainMenu;
        static int currentScene;

    public:
        static void Init();
        static bool Update();
        static void ChangeScene(int scene);
};

