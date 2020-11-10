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

/* ゲーム処理クラス */
class GameController {
    private:
        GameController();

    public:
        static unsigned long score;                     // スコア
        static int frame;                               // 経過フレーム
        static int scrapMagni;                          // スクラップ倍率
        static int scrapMagniGage;                      // スクラップ倍率ゲージ
        
        static StageBase* stage;                        // 現在ステージ格納
        static Player* player;                          // プレイヤー格納

        static void Init();                             // 初期化処理
        static void Init(int stageNum);                 // 初期化処理 - ステージ指定

        static void Update();                           // ゲーム更新
        static void Update_UI();                        // UI更新
        static void AddScore(int s, bool magni = true); // スコア加算(倍率有無)
};

