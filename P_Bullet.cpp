#include "P_Bullet.h"
P_Bullet::P_Bullet(Vector2* pos, double rad, Assets* img) : PlayerBullet(1, pos, rad, img) {
    velocity = 16;
    size = 16;
    cr = 10;
}

bool P_Bullet::MoveBullet() {
    if(hitted) return false;

    position.x += cos(angle) * velocity;
    position.y += sin(angle) * velocity;
    frame++;

    if(position.x < (double)GAME_WINDOW_X1-size || position.x >(double)GAME_WINDOW_X2+size || position.y < (double)GAME_WINDOW_Y1-size || position.y >(double)GAME_WINDOW_Y2+size) {
        return false;
    } else {
        return true;
    }
}

void P_Bullet::Draw() {
    DrawGraph(round(position.x) - size, round(position.y) - size, imgs->playerBullet01, TRUE);
}

bool P_Bullet::HitFunc() {
    if(!hitted) {
        hitted = true;
        return true;
    } else {
        return false;
    }
}