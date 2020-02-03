#include "DxLib.h"
#include "GameController.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // �E�B���h�E�ݒ� //
    ChangeWindowMode(TRUE);
    SetGraphMode(960, 720, 32);
    SetWindowSizeChangeEnableFlag(FALSE);
    if(DxLib_Init() == -1) return -1;
    
    // �Q�[������ //
    GameController game;

    SetDrawScreen(DX_SCREEN_BACK);

    while(ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        game.Update();
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}