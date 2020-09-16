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
    PBullet_Scraps();
    PBullet_Enemy();

    // 被弾判定は2fに1回 偶数F:被弾、奇数F:スクラップ
    if(gameCtrl->frame % 2 == 0) {
        if(!Player_EBullet()) Player_Enemy();
    } else {
        Player_Scraps();
    }
}

void CollisionCtrl::PBullet_Enemy() {
    if(enemyCtrl->enemysVec.size() != 0) {
        for(auto PB_itr : player->bulletVec) {
            if(PB_itr->active) {
                for(auto E_itr : enemyCtrl->enemysVec) {
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

void CollisionCtrl::PBullet_Scraps() {
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

bool CollisionCtrl::Player_Enemy() {
    for(auto enemy : enemyCtrl->enemysVec) {
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

bool CollisionCtrl::Player_EBullet() {
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

void CollisionCtrl::Player_Scraps() {
    for(auto S_itr : scrapsCtrl->scrapVec) {
        if(!S_itr->death) {
            if(CheckCollision(player->collider, S_itr->collider)) {
                player->HitFunc();
                S_itr->hitP = true;
            }
        }
    }
}