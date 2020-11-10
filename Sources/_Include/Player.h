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

/* プレイヤー基底クラス */
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

        void Moving(); // 移動
        void Shot();   // ショット、ミサイル
        void Bomber(); // ボンバー
        virtual void SetShot();         // ショット発射_V
        virtual void SetMissile();      // ミサイル発射_V
        virtual void AnimationBomber(); // ボンバーアニメーション_V

    public:
        Vector2 position;
        Collider* collider;
        std::vector<PlayerBullet*> bulletVec;
        bool bomber;
        int hitCT;

        Player();
        ~Player();
        void Update();            // 一連処理
        void DrawBullets();       // ショット、ミサイル描画
        virtual void DrawPlane(); // 機体描画_V
        virtual void HitFunc();   // 被弾処理_V
};

