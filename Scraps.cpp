#include "Scraps.h"
Scraps::Scraps(Vector2* pos) {
    position = *pos;
    death = false;
    hitP = false;

    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_real_distribution<double> rndX(-4, 4);
    std::uniform_real_distribution<double> rndY(-8, -2);
    x_vel = rndX(mt);
    y_vel = rndY(mt);

    frame = 0;
}
Scraps::~Scraps() {}

bool Scraps::Update() {
    if(!death) return Moving();
    else       return DeathFunc();
}

void Scraps::Dagame(int dmg) {
    HP -= dmg;
    if(HP <= 0) death = true;
}

bool Scraps::Moving() { return false; }
void Scraps::Draw() {}
bool Scraps::DeathFunc() { return false; }


Scrap_S::Scrap_S(Vector2* pos, Assets* imgs) : Scraps(pos) {
    HP = 2;
    image = imgs->scrap_S;
    collider = new Circle_C(&position, Vector2(0, 0), cr);
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
    if(position.x < cr || position.x > GAME_WINDOW_XSIZE - cr) {
        x_vel = -x_vel;
        position.x += x_vel;
    }

    collider->Update();

    frame++;

    if(position.y > GAME_WINDOW_YSIZE + cr) {
        death = true;
        return false;
    } else {
        return true;
    }
}

void Scrap_S::Draw() {
    int num = frame / 4 % 6;
    DrawGraph(round(position.x) - 20, round(position.y) - 20, image[num], TRUE);
}

bool Scrap_S::DeathFunc() {
    return false;
}