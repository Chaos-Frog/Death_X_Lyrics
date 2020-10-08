#include "DxLib.h"
#include "Vector2.h"
#include "Assets.h"
#include "SceneManager.h"
#include <cmath>
#include <thread>

using namespace std;

int screenGame; // �Q�[���X�N���[��
int screenFull; // �S�̃X�N���[��

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    /* �E�B���h�E�ݒ�  */
    /* �f�t�H 1280x720 */
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    SetWindowSizeChangeEnableFlag(FALSE);
    if(DxLib_Init() == -1) return -1;

    // ��ʔ䗦����
    const double ratio = 0.5625;
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
    
    // �X�N���[���쐬
    screenGame = MakeScreen(640, 720, TRUE);
    screenFull = MakeScreen(1280, 720, TRUE);

    // ���[�f�B���O����
    thread loadTherad(Assets::LoadAssets);

    while(ProcessMessage() == 0) {
        SetDrawScreen(screenFull);
        ClearDrawScreen();
        if(!Assets::DrawLoading()) break;

        SetDrawScreen(DX_SCREEN_BACK);
        ClearDrawScreen();
        DrawExtendGraph(xp1, yp1, xp2, yp2, screenFull, TRUE);
        ScreenFlip();
    }

    loadTherad.join();

    // �Q�[�����[�v
    while(ProcessMessage() == 0) {
        if(SceneManager::Update()) break;

        SetDrawScreen(DX_SCREEN_BACK);
        ClearDrawScreen();
        DrawExtendGraph(xp1, yp1, xp2, yp2, screenFull, TRUE);
        ScreenFlip();
    }

    // �I������
    DxLib_End();
    return 0;
}