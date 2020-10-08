#pragma once
#include "DxLib.h"
#include "Assets.h"
#include "SceneManager.h"
#include <iostream>
#include <string>

using namespace std;

struct MenuItem {
    string displayName;
    int stringWidth;
};

enum Menues {
    MAIN_MENU,
    SETTING_MENU,
    RANKING_MENU,
};

class MainMenu {
    private:
        MenuItem mainItem[4];
        MenuItem settingItem[8];

        int cursor_CT;
        int select_CT;
        
        int currentMenu;
        int menuState[2]       = { 0, 0 };
        int menuStateBarPos[2] = { 0, 0 };
        int menuStateBarTemp   = 0;

        int menuXpos;
        int settingXpos;

    public:
        MainMenu();
        bool Update();
        void Draw();
};

