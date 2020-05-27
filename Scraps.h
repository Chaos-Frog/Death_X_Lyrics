#pragma once
#include <cmath>
#include <random>
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"
#include "Collider.h"

class Scraps {
    private:
    protected:
        int frame;
        double x_vel, y_vel;
    public:
        int HP;
        Vector2 position;
        Collider* collider;

        Scraps(Vector2* pos);
        ~Scraps();
        virtual bool Moving();
        virtual void Draw();
};

class Scrap_S : public Scraps {
    private:
        int* image;

    public:
        double cr;

        Scrap_S(Vector2* pos, Assets* imgs);
        ~Scrap_S();
        bool Moving();
        void Draw();
};