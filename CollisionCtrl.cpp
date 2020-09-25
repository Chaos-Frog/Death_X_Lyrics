#include "CollisionCtrl.h"
#include "GameController.h"
CollisionCtrl::CollisionCtrl(GameController* gc) {
    gameCtrl = gc;
    player = gc->player;
    enemyCtrl = gc->eneCtrl;
    eBulletsCtrl = gc->ebulCtrl;
    scrapsCtrl = gc->scrCtrl;
}

CollisionCtrl::~CollisionCtrl() {}

void CollisionCtrl::Update() {
    Check_PBullet_Scraps_Collision();
    Check_PBullet_Enemy_Collision();

    // ”í’e”»’è‚Í2f‚É1‰ñ ‹ô”F:”í’eAŠï”F:ƒXƒNƒ‰ƒbƒv
    if(gameCtrl->frame % 2 == 0) {
        if(!Check_Player_EBullet_Collision()) Check_Player_Enemy_Collision();
    } else {
        Check_Player_Scraps_Collision();
    }
}

void CollisionCtrl::Check_PBullet_Enemy_Collision() {
    // ‹ó’†“G‚Æ‚Ì”»’è
    if(enemyCtrl->enemysVec_Air.size() != 0) {
        for(auto PB_itr : player->bulletVec) {
            if(PB_itr->active) {
                for(auto E_itr : enemyCtrl->enemysVec_Air) {
                    if(E_itr->HP > 0) {
                        for(auto enemyCol : E_itr->colliders) {
                            if(CheckCollision(PB_itr->collider, enemyCol)) {
                                if(PB_itr->HitFunc()) E_itr->Damage(1);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // ’nã“G‚Ì”»’è
    if(enemyCtrl->enemysVec_Ground.size() != 0) {
        for(auto PB_itr : player->bulletVec) {
            if(PB_itr->active) {
                for(auto E_itr : enemyCtrl->enemysVec_Ground) {
                    if(E_itr->HP > 0) {
                        for(auto enemyCol : E_itr->colliders) {
                            if(CheckCollision(PB_itr->collider, enemyCol)) {
                                if(PB_itr->HitFunc()) E_itr->Damage(1);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void CollisionCtrl::Check_PBullet_Scraps_Collision() {
    if(scrapsCtrl->scrapVec.size() != 0) {
        for(auto PB_itr : player->bulletVec) {
            if(PB_itr->bulletType == 1 && PB_itr->active) {
                for(auto S_itr : scrapsCtrl->scrapVec) {
                    if(!S_itr->death) {
                        if(CheckCollision(PB_itr->collider, S_itr->collider)) {
                            if(PB_itr->HitFunc()) {
                                S_itr->Dagame(1);
                                if(S_itr->HP <= 0) gameCtrl->AddScore(10, false);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

bool CollisionCtrl::Check_Player_Enemy_Collision() {
    for(auto enemy : enemyCtrl->enemysVec_Air) {
        if(!enemy->onGround) {
            for(auto col : enemy->colliders) {
                if(CheckCollision(player->collider, col)) {
                    player->HitFunc();
                    return true;
                }
            }
        }
    }
    return false;
}

bool CollisionCtrl::Check_Player_EBullet_Collision() {
    for(auto eBullet : eBulletsCtrl->bulletsVec) {
        if(!eBullet->death) {
            if(CheckCollision(eBullet->collider, player->collider)) {
                eBullet->DeathFunc();
                player->HitFunc();
                return true;
            }
        }
    }
    return false;
}

void CollisionCtrl::Check_Player_Scraps_Collision() {
    for(auto S_itr : scrapsCtrl->scrapVec) {
        if(!S_itr->death) {
            if(CheckCollision(player->collider, S_itr->collider)) {
                player->HitFunc();
                S_itr->hitP = true;
            }
        }
    }
}