#pragma once
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "EnemyCtrl.h"
#include <string>
#include <vector>
class GameController;

using namespace std;

class StageBase {
    protected:
        int frame;
        int stageNum;
        int enemyCount;
        GameController* gameCtrl;
        EnemyCtrl* enemyCtrl;

        void SetStageEnemy();

    public:
        Vector2 groundPos; // �n����W�i�}�b�v����(0, 0)�j

        StageBase(GameController* gc, int stNum);
        ~StageBase();
        virtual void Update();
        virtual void BG_Update();
        virtual void BG_Draw();

};

