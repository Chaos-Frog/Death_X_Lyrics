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

#define MOVE_X_MAX GAME_WINDOW_XSIZE - 60.0
#define MOVE_X_MIN 60.0
#define MOVE_Y_MAX GAME_WINDOW_YSIZE - 60.0
#define MOVE_Y_MIN 60.0

class Player {
    protected:
        Assets* imgs;
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

        Player(Assets* img);
        ~Player();
        void Update();            // ��A����
        void DrawBullets();       // �V���b�g�A�~�T�C���`��
        virtual void DrawPlane(); // �@�̕`��_V
        virtual void HitFunc();   // ��e����_V
};

