#include "MainMenu.h"

MainMenu::MainMenu() {
    SetFontSize(24);
    mainItem[0].displayName = "Game Start";
    mainItem[1].displayName = "Setting";
    mainItem[2].displayName = "Ranking";
    mainItem[3].displayName = "Quit";
    for(int i = 0; i < 4; i++) {
        int length = mainItem[i].displayName.length();
        mainItem[i].stringWidth = GetDrawStringWidth(mainItem[i].displayName.c_str(), length);
    }

    settingItem[0].displayName = "Setting[1]";
    settingItem[1].displayName = "Setting[2]";
    settingItem[2].displayName = "Setting[3]";
    settingItem[3].displayName = "Setting[4]";
    settingItem[4].displayName = "Setting[5]";
    settingItem[5].displayName = "Setting[6]";
    settingItem[6].displayName = "Setting[7]";
    settingItem[7].displayName = "Setting[8]";
    for(int i = 0; i < 8; i++) {
        int length = settingItem[i].displayName.length();
        settingItem[i].stringWidth = GetDrawStringWidth(settingItem[i].displayName.c_str(), length);
    }

    currentMenu = MAIN_MENU;

    menuXpos = 0;
    settingXpos = 0;

    cursor_CT = 0;
    select_CT = 0;
}

bool MainMenu::Update() {
    if(cursor_CT == 0 && select_CT == 0) {
        if(currentMenu == MAIN_MENU) {
            if(CheckHitKey(KEY_INPUT_RETURN) || CheckHitKey(KEY_INPUT_RIGHT)) {
                switch(menuState[MAIN_MENU]) {
                    case 0:
                        SceneManager::ChangeScene(SCENE_GAME);
                        return true;
                        break;
                    case 1:
                        currentMenu = SETTING_MENU;
                        select_CT = 30;
                        break;

                    case 2:
                        currentMenu = RANKING_MENU;
                        select_CT = 30;
                        break;
                    
                    case 3:
                        return false;
                        break;

                    default:
                        break;
                }
            } else {
                if(CheckHitKey(KEY_INPUT_UP)) {
                    if(menuState[MAIN_MENU] > 0) {
                        menuState[MAIN_MENU]--;
                        menuStateBarTemp = menuStateBarPos[MAIN_MENU];
                        cursor_CT = 10;
                    }
                }
                if(CheckHitKey(KEY_INPUT_DOWN)) {
                    if(menuState[MAIN_MENU] < 3) {
                        menuState[MAIN_MENU]++;
                        menuStateBarTemp = menuStateBarPos[MAIN_MENU];
                        cursor_CT = 10;
                    }
                }
            }
        } else {
            if(CheckHitKey(KEY_INPUT_LEFT)) {
                currentMenu = MAIN_MENU;
                select_CT = 30;
            } else {
                if(currentMenu == SETTING_MENU) {
                    if(CheckHitKey(KEY_INPUT_UP)) {
                        if(menuState[SETTING_MENU] > 0) {
                            menuState[SETTING_MENU]--;
                            menuStateBarTemp = menuStateBarPos[SETTING_MENU];
                            cursor_CT = 10;
                        }
                    }
                    if(CheckHitKey(KEY_INPUT_DOWN)) {
                        if(menuState[SETTING_MENU] < 7) {
                            menuState[SETTING_MENU]++;
                            menuStateBarTemp = menuStateBarPos[SETTING_MENU];
                            cursor_CT = 10;
                        }
                    }
                }
            }
        }
    }

    if(cursor_CT != 0) {
        double t = (10.0 - cursor_CT) / 10.0;

        int step = 0;
        if(currentMenu == MAIN_MENU)         step = 60;
        else if(currentMenu == SETTING_MENU) step = 30;

        int dif = (menuState[currentMenu] * step) - menuStateBarTemp;
        menuStateBarPos[currentMenu] = -dif * t * (t - 2.0) + menuStateBarTemp;

        cursor_CT--;
    }

    if(select_CT != 0) {
        if(currentMenu != MAIN_MENU) {
            double t = (30.0 - select_CT) / 30.0;
            menuXpos = -300 * t * (t - 2.0);
            if(currentMenu == SETTING_MENU) {
                settingXpos = -760 * t * (t - 2.0);
            } 
        } else {
            double t = (30.0 - select_CT) / 30.0;
            menuXpos = 300 * t * (t - 2.0) + 300;
            if(settingXpos > 0) {
                settingXpos = 760 * t * (t - 2.0) + 760;
            }
        }
        select_CT--;
    }

    Draw();

    return true;
}

void MainMenu::Draw() {
    DrawBox(0, 0, 1280, 720, GetColor(0, 0, 0), TRUE);

    DrawBox(520 - menuXpos, 240 + menuStateBarPos[MAIN_MENU], 760 - menuXpos, 264 + menuStateBarPos[MAIN_MENU], GetColor(0, 60, 0), TRUE);

    SetFontSize(24);
    DrawString((1280 - mainItem[0].stringWidth) / 2 - menuXpos, 240, mainItem[0].displayName.c_str(), GetColor(0, 200, 0));
    DrawString((1280 - mainItem[1].stringWidth) / 2 - menuXpos, 300, mainItem[1].displayName.c_str(), GetColor(0, 200, 0));
    DrawString((1280 - mainItem[2].stringWidth) / 2 - menuXpos, 360, mainItem[2].displayName.c_str(), GetColor(0, 200, 0));
    DrawString((1280 - mainItem[3].stringWidth) / 2 - menuXpos, 420, mainItem[3].displayName.c_str(), GetColor(0, 200, 0));

    if(settingXpos > 0) {
        DrawBox(520 + (760 - settingXpos), 240 + menuStateBarPos[SETTING_MENU], 760 + (760 - settingXpos), 264 + menuStateBarPos[SETTING_MENU], GetColor(0, 60, 0), TRUE);

        for(int i = 0; i < size(settingItem); i++) {
            DrawString((1280 - settingItem[i].stringWidth) / 2 + (760 - settingXpos), 240+(30*i), settingItem[i].displayName.c_str(), GetColor(0, 200, 0));
        }
    }
}