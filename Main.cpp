#include <cmath>
#include "DxLib.h"
#include "GameController.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // ウィンドウ設定 //
    // デフォ 1280x720 //
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    SetWindowSizeChangeEnableFlag(FALSE);
    if(DxLib_Init() == -1) return -1;

    double ratio = 0.5625;
    int sizeX, sizeY, cb;
    GetScreenState(&sizeX, &sizeY, &cb);
    int xp1, xp2, yp1, yp2;
    if(sizeX * ratio >= sizeY) {
        double difX = (sizeX - sizeY / ratio) / 2;
        xp1 = round(difX);
        xp2 = round(sizeX - difX);
        yp1 = 0;
        yp2 = sizeY;
    } else {
        double difY = (sizeY - sizeX * ratio) / 2;
        xp1 = 0;
        xp2 = sizeX;
        yp1 = round(difY);
        yp2 = round(sizeY - difY);
    }
    
    // ゲーム処理 //
    Assets image;
    GameController game(&image);
    int screen = MakeScreen(1280, 720, TRUE);


    while(ProcessMessage() == 0&& CheckHitKey(KEY_INPUT_ESCAPE) != 1) {
        SetDrawScreen(screen);
        ClearDrawScreen();

        game.Update();

        SetDrawScreen(DX_SCREEN_BACK);
        ClearDrawScreen();

        DrawExtendGraph(xp1, yp1, xp2, yp2, screen, TRUE);
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}