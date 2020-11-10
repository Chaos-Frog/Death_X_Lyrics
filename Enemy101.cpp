#include "Enemy101.h"
#include "GameController.h"

#define E101_X_SIZE 30
#define E101_Y_SIZE 60


Enemy101::Enemy101(Vector2* pos, int mp, int dp)
         :Enemy_Ground(101, pos, 1, 1, mp, dp) {
    first = *pos;
    enableArea = {
        Vector2(-E101_X_SIZE, -E101_Y_SIZE),
        Vector2((double)GAME_WINDOW_XSIZE + E101_X_SIZE, (double)GAME_WINDOW_YSIZE + E101_Y_SIZE)
    };

    colliders.emplace_back(new Box_C(&position, Vector2(0, 0), E101_X_SIZE, E101_Y_SIZE));
}

void Enemy101::MovingGround() {
    if(position.y > GAME_WINDOW_YSIZE / 2) withdrawal = true;
    groundPos.y += 1;
}

void Enemy101::Danmaku() {

}

void Enemy101::Draw() {
    DrawBox(position.x-(E101_X_SIZE/2.0), position.y+(E101_Y_SIZE/2.0), position.x+(E101_X_SIZE/2.0), position.y-(E101_Y_SIZE/2.0), GetColor(0, 0, 200), TRUE);
    DrawBox(position.x-(E101_X_SIZE/4.0), position.y+(E101_Y_SIZE/4.0), position.x+(E101_X_SIZE/4.0), position.y-(E101_Y_SIZE/4.0), GetColor(0, 0, 60), TRUE);
}

bool Enemy101::DeathFunc() {
    return false;
}
