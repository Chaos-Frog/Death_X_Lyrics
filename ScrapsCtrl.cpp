#include "ScrapsCtrl.h"
#include "GameController.h"
ScrapsCtrl::ScrapsCtrl(Assets* imgs, GameController* gc) {
    images = imgs;
    gameCtrl = gc;
}
ScrapsCtrl::~ScrapsCtrl() {}

void ScrapsCtrl::Update() {
    for(auto itr = scrapVec.begin(); itr != scrapVec.end();) {
        if((*itr)->Moving()) {
            ++itr;
        } else {
            itr = scrapVec.erase(itr);
            if(gameCtrl->scrapMagni > 10 && gameCtrl->scrapMagniGage == 0) gameCtrl->scrapMagni -= 1;
        }
    }
}

void ScrapsCtrl::Draw() {
    for(auto sc : scrapVec) {
        sc->Draw();
    }
}

void ScrapsCtrl::SetScrap(int type, Vector2* pos) {
    if(type == 1) scrapVec.emplace_back(new Scrap_S(pos, images));
}