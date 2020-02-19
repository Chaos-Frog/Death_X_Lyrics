#pragma once
#include <vector>
#include <memory>
#include "Scrap_S.h"

class ScrapsCtrl {
    private:
        Assets* images;
    public:
        std::vector<std::shared_ptr<Scrap_S>> scrapVec;

        ScrapsCtrl(Assets* imgs);
        ~ScrapsCtrl();
        void Update();
        void SetScrap(int type, Vector2* pos);
};

