#include "P_Missile.h"
P_Missile::P_Missile(Vector2* pos, double rad, Assets* img) : PlayerBullet(2, pos, rad, img) {
    velocity = 0;
    size = 32;
    cr = 20;
    hitted = false;
}

bool P_Missile::MoveBullet() {
    if(!hitted) {
        if(frame <= 60) {
            double t = (double)frame / 60.0;
            velocity = 20.0 * t * t;
        }
        position.x += cos(angle) * velocity;
        position.y += sin(angle) * velocity;
        frame++;
    } else {
        position.y -= velocity;
        frame++;
        if(frame == 32) {
            return false;
        }
    }

    if(position.x < (double)GAME_WINDOW_X1 - size || position.x >(double)GAME_WINDOW_X2 + size || position.y < (double)GAME_WINDOW_Y1 - size || position.y >(double)GAME_WINDOW_Y2 + size) {
        return false;
    } else {
        return true;
    }
}

void P_Missile::Draw() {
    if(!hitted) DrawGraph(round(position.x) - size, round(position.y) - size, imgs->playerMissile, TRUE);
    else        DrawGraph(round(position.x) - size, round(position.y) - size, imgs->playerMissileExp[frame / 2], TRUE);
}

bool P_Missile::HitFunc() {
    if(!hitted) {
        frame = 0;
        velocity = 2;
        hitted = true;
        size = 50;
        cr = 40;
    }
    return false;
}
