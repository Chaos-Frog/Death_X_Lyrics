#pragma once
#include "DxLib.h"
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"
#include <vector>

class Boss {
    protected:
        int frame;
        int phase;
        int score;
    
    public:
        int HP;
        Vector2 position;

        Boss();
        ~Boss();

        virtual bool Update();                 // 更新処理
        virtual void Draw();                   // 描画処理
        virtual bool DeathFunc();              // 死亡時処理

        void CheckBossCollision();             // ボス当たり判定
        virtual void CheckCol_Boss_PBullets(); // Boss & PlayerBullets
        virtual void CheckCol_Boss_Player();   // Boss & Player
};

