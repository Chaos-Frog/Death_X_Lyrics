#include "Enemy_Air.h"

Enemy_Air::Enemy_Air(Enemys type, Vector2* pos, int mp, int dp)
          :Enemy(type, pos, mp, dp, false) {
}

bool Enemy_Air::Moving() {
    MovingAir();
    return CheckInArea();
}
void Enemy_Air::MovingAir(){}

bool Enemy_Air::CheckInArea() {
    if(withdrawal) {
        return enableArea.min.x <= position.x && position.x <= enableArea.max.x
            && enableArea.min.y <= position.y && position.y <= enableArea.max.y;
    }
    return true;
}