#include "StageBase.h"
#include "GameController.h"

StageBase::StageBase(GameController* gc, int stNum) {
    gameCtrl = gc;
    enemyCtrl = gc->eneCtrl;

    frame = 0;
    stageNum = stNum;
    groundPos = Vector2(0, 0);
    enemyCount = 0;
}
StageBase::~StageBase(){}
void StageBase::Update(){}
void StageBase::BG_Update(){}
void StageBase::BG_Draw(){}

void StageBase::SetStageEnemy() {
    while(Assets::Stages[stageNum].size() != enemyCount) {
        if(Assets::Stages[stageNum][enemyCount].frame == frame) {
            EnemyData ed = Assets::Stages[stageNum][enemyCount];
            gameCtrl->eneCtrl->SetEnemy(ed.enemyType, &ed.setPos, ed.movePatern, ed.danmakuPatern);
            enemyCount++;
        } else {
            break;
        }
    }
}