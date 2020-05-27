#pragma once
#include <vector>
#include <memory>
#include "Scraps.h"

class GameController;

class ScrapsCtrl {
    private:
        Assets* images;
        GameController* gameCtrl;
    public:
        std::vector<Scraps *> scrapVec;

        ScrapsCtrl(Assets* imgs, GameController* gc);
        ~ScrapsCtrl();
        void Update();
        void Draw();
        void SetScrap(int type, Vector2* pos);
};

