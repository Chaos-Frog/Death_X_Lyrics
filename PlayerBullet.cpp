#include "PlayerBullet.h"
PlayerBullet::PlayerBullet(int type, Vector2 pos, double rad) {
    bulletType = type;
    position = pos;
    angle = rad;
    hitted = false;
    active = true;
    frame = 0;
}
PlayerBullet::~PlayerBullet() {}

bool PlayerBullet::Update() {
    if(MoveBullet()) {
        return true;
    } else {
        active = false;
        return false;
    }
}

bool PlayerBullet::MoveBullet() { return false; }
void PlayerBullet::Draw() {}
bool PlayerBullet::HitFunc() { return false; }


P_Bullet::P_Bullet(Vector2 pos, double rad) : PlayerBullet(1, pos, rad) {
    velocity = 20;
    size = 16;
    collider = new Circle_C(&position, Vector2(0, 0), 10.0f);
}

bool P_Bullet::MoveBullet() {
    if(hitted) return false;

    position.x += cos(angle) * velocity;
    position.y += sin(angle) * velocity;
    frame++;

    collider->Update();

    if(position.x < -size || position.x > (double)GAME_WINDOW_XSIZE + size || position.y < -size || position.y > (double)GAME_WINDOW_YSIZE + size) {
        return false;
    } else {
        return true;
    }
}

void P_Bullet::Draw() {
    DrawGraph(round(position.x) - size, round(position.y) - size, Assets::playerBullet01, TRUE);
}

bool P_Bullet::HitFunc() {
    if(!hitted) {
        hitted = true;
        return true;
    } else {
        return false;
    }
}


P_Missile::P_Missile(Vector2 pos, double rad) : PlayerBullet(2, pos, rad) {
    velocity = 0;
    size = 32;
    collider = new Box_C(&position, Vector2(0, 0), 32.0f, 64.0f);
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

    collider->Update();

    if(position.x < -size || position.x > (double)GAME_WINDOW_XSIZE + size || position.y < -size || position.y > (double)GAME_WINDOW_YSIZE + size) {
        return false;
    } else {
        return true;
    }
}

void P_Missile::Draw() {
    if(!hitted) DrawGraph(round(position.x) - size, round(position.y) - size, Assets::playerMissile, TRUE);
    else        DrawGraph(round(position.x) - size, round(position.y) - size, Assets::playerMissileExp[frame / 2], TRUE);
}

bool P_Missile::HitFunc() {
    if(!hitted) {
        frame = 0;
        velocity = 2;
        hitted = true;
        size = 50;
        collider = new Circle_C(&position, Vector2(0, 0), 40.0f);
    }
    return true;
}