#pragma once
#include <vector>
#include <memory>
#include "Scraps.h"

class ScrapsCtrl {
    private:
        ScrapsCtrl();

    public:
        static std::vector<Scraps *> scrapVec;

        static void Init();

        static void Update();
        static void Draw();
        static void SetScrap(int type, Vector2 pos, int num = 1);
};

