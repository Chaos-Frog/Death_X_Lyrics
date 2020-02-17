#include "PlayerBullet.h"
PlayerBullet::PlayerBullet(int type, Vector2* pos, double rad, Assets* img) {
    bulletType = type;
    position = *pos;
    angle = rad;
    imgs = img;
    frame = 0;
}

PlayerBullet::~PlayerBullet() {
}

bool PlayerBullet::MoveBullet() { return false; }
bool PlayerBullet::HitFunc() { return false; }