#include "Scraps.h"
Scraps::Scraps(Vector2* pos) {
    position = *pos;

    std::random_device rnd;
    std::mt19937 mtx(rnd());
    std::uniform_real_distribution<double> rndX(-4, 4);
    std::mt19937 mty(rnd());
    std::uniform_real_distribution<double> rndY(-8, -2);
    x_vel = rndX(mtx);
    y_vel = rndY(mty);

    frame = 0;
}

Scraps::~Scraps() {}

bool Scraps::Moving() { return false; }

void Scraps::Draw() {}