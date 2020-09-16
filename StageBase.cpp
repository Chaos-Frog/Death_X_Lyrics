#include "StageBase.h"
#include "GameController.h"

StageBase::StageBase(GameController* gc, Assets* as, int stNum) {
    frame = 0;
    stageNum = stNum;
    enemyCount = 0;
    gameCtrl = gc;
    assets = as;
}
StageBase::~StageBase(){}
void StageBase::Update(){}
void StageBase::BG_Update(){}
void StageBase::BG_Draw(){}

void StageBase::SetStageEnemy() {
    while(assets->Stages[stageNum].size() != enemyCount) {
        if(assets->Stages[stageNum][enemyCount].frame == frame) {
            EnemyData ed = assets->Stages[stageNum][enemyCount];
            gameCtrl->eneCtrl->SetEnemy(ed.enemyType, &ed.setPos, ed.movePatern, ed.danmakuPatern);
            enemyCount++;
        } else {
            break;
        }
    }
}