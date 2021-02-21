#pragma once
#define _USE_MATH_DEFINES
#include "Vector2.h"
#include "Collider.h"
#include "Define.h"
#include <cmath>
#include <vector>

/* 存在可能範囲 構造体 */
struct EnableArea {
    Vector2 min;
    Vector2 max;
};

/* 敵 基底クラス */
class Enemy {
    private:
    protected:
        int frame;                        // 経過時間（フレーム）
        int movePatern;                   // 移動パターン
        int danmakuPatern;                // 弾幕パターン
        EnableArea enableArea;            // 生存可能範囲

        virtual bool Moving();            // 移動処理 離脱した場合falseを返す
        virtual void Danmaku();           // 弾幕処理
        virtual bool CheckInArea();       // 指定範囲内かチェック 
        double TargetPlayerAngle();       // プレイヤー追尾角度

    public:
        Vector2 position;                 // 座標
        std::vector<Collider*> colliders; // 当たり判定Vector
        int enemyType;                    // 敵タイプ
        int HP;                           // 耐久力
        int score;                        // スコア値
        bool invincible;                  // 無敵状態
        bool withdrawal;                  // 離脱状態
        bool onGround;                    // 地上物判定

        Enemy(Enemys type, Vector2* pos, int mp, int dp, bool onG);
        bool Update();                    // 更新処理
        void Damage(int dmg);             // damage処理
        virtual void Draw();              // 描画処理
        virtual bool DeathFunc();         // 撃破時処理 終了したらfalseを返す
};

