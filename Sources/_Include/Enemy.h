#pragma once
#define _USE_MATH_DEFINES
#include "Vector2.h"
#include "Collider.h"
#include "Define.h"
#include <cmath>
#include <vector>

/* ���݉\�͈� �\���� */
struct EnableArea {
    Vector2 min;
    Vector2 max;
};

/* �G ���N���X */
class Enemy {
    private:
    protected:
        int frame;                        // �o�ߎ��ԁi�t���[���j
        int movePatern;                   // �ړ��p�^�[��
        int danmakuPatern;                // �e���p�^�[��
        EnableArea enableArea;            // �����\�͈�

        virtual bool Moving();            // �ړ����� ���E�����ꍇfalse��Ԃ�
        virtual void Danmaku();           // �e������
        virtual bool CheckInArea();       // �w��͈͓����`�F�b�N 
        double TargetPlayerAngle();       // �v���C���[�ǔ��p�x

    public:
        Vector2 position;                 // ���W
        std::vector<Collider*> colliders; // �����蔻��Vector
        int enemyType;                    // �G�^�C�v
        int HP;                           // �ϋv��
        int score;                        // �X�R�A�l
        bool invincible;                  // ���G���
        bool withdrawal;                  // ���E���
        bool onGround;                    // �n�㕨����

        Enemy(Enemys type, Vector2* pos, int mp, int dp, bool onG);
        bool Update();                    // �X�V����
        void Damage(int dmg);             // damage����
        virtual void Draw();              // �`�揈��
        virtual bool DeathFunc();         // ���j������ �I��������false��Ԃ�
};

