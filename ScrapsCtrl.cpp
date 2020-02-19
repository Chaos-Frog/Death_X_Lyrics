#include "ScrapsCtrl.h"
ScrapsCtrl::ScrapsCtrl(Assets* imgs) { images = imgs; }
ScrapsCtrl::~ScrapsCtrl() {}

void ScrapsCtrl::Update() {
    for(auto itr = scrapVec.begin(); itr != scrapVec.end();) {
        if((*itr)->Moving()) {
            (*itr)->Draw();
            ++itr;
        } else {
            itr = scrapVec.erase(itr);
        }
    }
}

void ScrapsCtrl::SetScrap(int type, Vector2* pos) {
    scrapVec.emplace_back(std::make_shared<Scrap_S>(pos, images));
}