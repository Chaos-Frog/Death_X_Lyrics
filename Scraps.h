#pragma once
#include <cmath>
#include <random>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"

class Scraps {
    private:
    protected:
        int frame;
        double x_vel, y_vel;
    public:
        int HP;
        Vector2 position;

        Scraps(Vector2* pos);
        ~Scraps();
        virtual bool Moving();
        virtual void Draw();
};

