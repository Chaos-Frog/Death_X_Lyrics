#include "StageBase.h"
#include "GameController.h"
#include "EnemyCtrl.h"

StageBase::StageBase(int stNum) {
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
            EnemyCtrl::SetEnemy(ed.enemyType, &ed.setPos, ed.movePatern, ed.danmakuPatern);
            enemyCount++;
        } else {
            break;
        }
    }
}