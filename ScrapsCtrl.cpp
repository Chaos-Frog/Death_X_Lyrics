#include "ScrapsCtrl.h"
#include "GameController.h"

std::vector<Scraps*> ScrapsCtrl::scrapVec;

void ScrapsCtrl::Init() {
    scrapVec.clear();
}

void ScrapsCtrl::Update() {
    for(auto itr = scrapVec.begin(); itr != scrapVec.end();) {
        if((*itr)->Update()) {
            ++itr;
        } else {
            if((*itr)->HP > 0) {
                if((*itr)->hitP) {
                    if(GameController::scrapMagni > 10) GameController::scrapMagni--;
                    GameController::scrapMagniGage = 0;
                } else {
                    if(GameController::scrapMagni > 10 && GameController::scrapMagniGage == 0) GameController::scrapMagni--;
                }
            } else {
                if(GameController::scrapMagni < 100) GameController::scrapMagni++;
                GameController::scrapMagniGage = 100;

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