#pragma once
#include "Player.h"

#define SIZE_X 120
#define SIZE_Y 100
#define SPEED 4

class Player_A : public Player {
    private:
        int* playerImgs;
        int* playerImgs_Hit;

        void SetShot() override;         // �V���b�g����
        void SetMissile() override;      // �~�T�C������
        void AnimationBomber() override; // �{���o�[�A�j���[�V����

    public:
        Player_A(Assets* imgs);
        ~Player_A();
        void DrawPlane() override; // �@�̕`��
        void HitFunc() override;   // ��e����
};

