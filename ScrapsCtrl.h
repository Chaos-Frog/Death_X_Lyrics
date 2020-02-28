#pragma once
#include <vector>
#include <memory>
#include "Scrap_S.h"

class GameController;

class ScrapsCtrl {
    private:
        Assets* images;
        GameController* gameCtrl;
    public:
        std::vector<std::shared_ptr<Scrap_S>> scrapVec;

        ScrapsCtrl(Assets* imgs, GameController* gc);
        ~ScrapsCtrl();
        void Update();
        void Draw();
        void SetScrap(int type, Vector2* pos);
};

