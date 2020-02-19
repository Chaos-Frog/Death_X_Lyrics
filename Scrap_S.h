#pragma once
#include "Scraps.h"
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

