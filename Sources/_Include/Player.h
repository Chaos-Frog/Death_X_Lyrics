#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <random>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"
#include "PlayerBullet.h"

/* �v���C���[���N���X */
class Player {
    private:
    protected:
        double speed;
        int frame;
        int imgNum;
        int rotate;
        int shotCT;
        int missileCT;
        int bomberCT;

        void Moving(); // �ړ�
        void Shot();   // �V���b�g�A�~�T�C��
        void Bomber(); // �{���o�[
        virtual void SetShot();         // �V���b�g����_V
        virtual void SetMissile();      // �~�T�C������_V
        virtual void AnimationBomber(); // �{���o�[�A�j���[�V����_V

    public:
        Vector2 position;
        Collider* collider;
        std::vector<PlayerBullet*> bulletVec;
        bool bomber;
        int hitCT;

        Player();
        ~Player();
        void Update();            // ��A����
        void DrawBullets();       // �V���b�g�A�~�T�C���`��
        virtual void DrawPlane(); // �@�̕`��_V
        virtual void HitFunc();   // ��e����_V
};

