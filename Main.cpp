#include "DxLib.h"
#include "GameController.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // �E�B���h�E�ݒ� //
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    SetWindowSizeChangeEnableFlag(FALSE);
    if(DxLib_Init() == -1) return -1;
    
    // �Q�[������ //
    Assets image;
    GameController game(&image);

    SetDrawScreen(DX_SCREEN_BACK);

    while(ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1) {
        game.Update();
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}