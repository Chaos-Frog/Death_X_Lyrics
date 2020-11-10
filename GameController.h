#pragma once
#include <stdio.h>
#include <string>
#include <random>
#include "DxLib.h"
#include "Define.h"
#include "Assets.h"
#include "SceneManager.h"

#include "Player_A.h"
#include "Stage_1.h"

/* �Q�[�������N���X */
class GameController {
    private:
        GameController();

    public:
        static unsigned long score;                     // �X�R�A
        static int frame;                               // �o�߃t���[��
        static int scrapMagni;                          // �X�N���b�v�{��
        static int scrapMagniGage;                      // �X�N���b�v�{���Q�[�W
        
        static StageBase* stage;                        // ���݃X�e�[�W�i�[
        static Player* player;                          // �v���C���[�i�[

        static void Init();                             // ����������
        static void Init(int stageNum);                 // ���������� - �X�e�[�W�w��

        static void Update();                           // �Q�[���X�V
        static void Update_UI();                        // UI�X�V
        static void AddScore(int s, bool magni = true); // �X�R�A���Z(�{���L��)
};

