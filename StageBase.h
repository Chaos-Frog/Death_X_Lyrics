#pragma once
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include <string>
#include <vector>

using namespace std;

class StageBase {
    protected:
        int frame;
        int stageNum;
        int enemyCount;

        void SetStageEnemy();

    public:
        Vector2 groundPos; // 地上座標（マップ左下(0, 0)）

        StageBase(int stNum);
        ~StageBase();
        virtual void Update();
        virtual void BG_Update();
        virtual void BG_Draw();

};

