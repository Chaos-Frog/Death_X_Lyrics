#include "PlayerBullet.h"
PlayerBullet::PlayerBullet(int type, Vector2* pos, double rad, int* img) {
    bulletType = type;
    position.x = pos->x;
    position.y = pos->y;
    angle = rad;

    bulletImg = img;
}

bool PlayerBullet::MoveBullet() {
    switch(bulletType) {
        case 0:
            position.x += cos(angle) * 10.0;
            position.y += sin(angle) * 10.0;
            break;
        default:
            break;
    }
    if(position.x < 320 || position.x > 960 || position.y < 0 || position.y > 720) {
        return false;
    } else {
        DrawGraph(round(position.x) - 32, round(position.y) - 32, *bulletImg, TRUE);
        return true;
    }
}