#pragma once
#include "DxLib.h"
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"
#include "ScrapsCtrl.h"
#include <vector>
class GameController;

class Boss {
    protected:
        int frame;
        int phase;
        int score;
        GameController* gameController;
    
    public:
        int HP;
        Vector2 position;

        Boss(GameController* gc);
        ~Boss();
        virtual bool Update();    // �X�V����
        virtual void Draw();      // �`�揈��
        virtual bool DeathFunc(); // ���S������

        void CheckBossCollision();             // �{�X�����蔻��
        virtual void CheckCol_Boss_PBullets(); // Boss & PlayerBullets
        virtual void CheckCol_Boss_Player();   // Boss & Player
};

