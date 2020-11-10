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
        ImageData* image;
        int frame;
        double x_vel, y_vel;

    public:
        int HP;
        bool death, hitP;
        Vector2 position;
        Collider* collider;

        Scraps(Vector2 pos, ImageData* id, int hp, Collider* col);
        ~Scraps();
        bool Update();
        void Dagame(int dmg);
        virtual bool Moving();
        virtual void Draw();
        virtual bool DeathFunc();
};

class Scrap_S : public Scraps {
    private:
        double cr = 16;

    public:
        Scrap_S(Vector2 pos);
        ~Scrap_S();
        bool Moving() override;
        void Draw() override;
        bool DeathFunc() override;
};