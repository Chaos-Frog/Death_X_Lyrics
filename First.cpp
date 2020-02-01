#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // ウィンドウ設定 //
    ChangeWindowMode(TRUE);
    SetGraphMode(960, 720, 32);
    SetWindowSizeChangeEnableFlag(FALSE);
    if(DxLib_Init() == -1) return -1;
    
    // ゲーム処理 //
    SetDrawScreen(DX_SCREEN_BACK);

    char text[] = "Death_X_Lyrics";
    char text2[] = "NOW UNDER DEVELOPMENT...";
    int length = sizeof(text) / sizeof(text[0]);
    int length2 = sizeof(text2) / sizeof(text2[0]);

    while(ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        SetFontSize(72);
        int textWidth = GetDrawStringWidth(text, length);
        DrawString(480-(textWidth/2), 320 - 36, text, GetColor(255, 255, 255));
        SetFontSize(26);
        textWidth = GetDrawStringWidth(text2, length2);
        DrawString(480 - (textWidth / 2), 420 - 36, text2, GetColor(255, 255, 255));
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}