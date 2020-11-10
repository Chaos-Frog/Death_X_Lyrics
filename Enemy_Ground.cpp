#include "Enemy_Ground.h"
#include "GameController.h"

Enemy_Ground::Enemy_Ground(int type, Vector2* pos, int hp, int s, int mp, int dp)
             :Enemy(type, pos, hp, s, mp, dp, true) {
    stageGroundPos = &(GameController::stage->groundPos);
    groundPos = *pos;
    position = groundPos - *stageGroundPos;
}

bool Enemy_Ground::Moving() {
    MovingGround();
    position = groundPos - *stageGroundPos;
    return CheckInArea();
}
void Enemy_Ground::MovingGround(){}

bool Enemy_Ground::CheckInArea() {
    if(withdrawal) {
        return enableArea.min.x <= position.x && position.x <= enableArea.max.x
            && enableArea.min.y <= position.y && position.y <= enableArea.max.y;
    }
    return true;
}