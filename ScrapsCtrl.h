#pragma once
#include <vector>
#include <memory>
#include "Scraps.h"

class GameController;

class ScrapsCtrl {
    private:
        GameController* gameCtrl;

    public:
        std::vector<Scraps *> scrapVec;

        ScrapsCtrl(GameController* gc);
        ~ScrapsCtrl();
        void Update();
        void Draw();
        void SetScrap(int type, Vector2 pos);
};

