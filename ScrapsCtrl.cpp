#include "ScrapsCtrl.h"
#include "GameController.h"
ScrapsCtrl::ScrapsCtrl(GameController* gc) {
    gameCtrl = gc;
}
ScrapsCtrl::~ScrapsCtrl() {}

void ScrapsCtrl::Update() {
    for(auto itr = scrapVec.begin(); itr != scrapVec.end();) {
        if((*itr)->Update()) {
            ++itr;
        } else {
            if((*itr)->HP > 0) {
                if((*itr)->hitP) {
                    if(gameCtrl->scrapMagni > 10) gameCtrl->scrapMagni--;
                    gameCtrl->scrapMagniGage = 0;
                } else {
                    if(gameCtrl->scrapMagni > 10 && gameCtrl->scrapMagniGage == 0) gameCtrl->scrapMagni--;
                }
            } else {
                if(gameCtrl->scrapMagni < 100) gameCtrl->scrapMagni++;
                gameCtrl->scrapMagniGage = 100;

            }
            itr = scrapVec.erase(itr);
        }
    }
}

void ScrapsCtrl::Draw() {
    for(auto sc : scrapVec) sc->Draw();
}

void ScrapsCtrl::SetScrap(int type, Vector2 pos, int num) {
    for(int i=0; i<num; i++) {
        if(type == 1) scrapVec.emplace_back(new Scrap_S(pos));
    }
}