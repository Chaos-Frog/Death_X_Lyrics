#pragma once
#include "Player.h"

#define SIZE_X 120
#define SIZE_Y 100
#define SPEED 4

class Player_A : public Player {
    private:
        int* playerImgs;
        int* playerImgs_Hit;

        void SetShot() override;         // ショット発射
        void SetMissile() override;      // ミサイル発射
        void AnimationBomber() override; // ボンバーアニメーション

    public:
        Player_A(Assets* imgs);
        ~Player_A();
        void DrawPlane() override; // 機体描画
        void HitFunc() override;   // 被弾処理
};

