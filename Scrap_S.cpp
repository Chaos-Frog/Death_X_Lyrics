#include "Scrap_S.h"
Scrap_S::Scrap_S(Vector2* pos, Assets* imgs) : Scraps(pos) {
    HP = 3;
    image = imgs->scrap_S;
    cr = 14;
}

Scrap_S::~Scrap_S() {}

bool Scrap_S::Moving() {
    if(x_vel < -2) {
        x_vel += 0.14;
        if(x_vel >= -2) x_vel = -2;
    } else if(x_vel > 2) {
        x_vel -= 0.14;
        if(x_vel <= 2) x_vel = 2;
    }

    if(y_vel <= 8.0) {
        y_vel += 0.1;
        if(y_vel >= 8.0) y_vel = 8.0;
    }

    position.x += x_vel;
    position.y += y_vel;
    if(position.x < 320+cr || position.x > 960-cr) {
        x_vel = -x_vel;
        position.x += x_vel;
    }

    frame++;

    if(position.y > 720 + cr) return false;
    else                      return true;
}

void Scrap_S::Draw() {
    int num = frame/4 % 6;
    DrawGraph(round(position.x)-20, round(position.y)-20, image[num], TRUE);
}