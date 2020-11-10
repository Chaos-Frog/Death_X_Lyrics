#include "CollisionCtrl.h"
#include "GameController.h"
#include "EnemyCtrl.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"

void CollisionCtrl::Update() {
    Check_PBullet_Scraps_Collision();
    Check_PBullet_Enemy_Collision();

    //EnemyCtrl::boss->CheckBossCollision();

    // ”í’e”»’è‚Í2f‚É1‰ñ ‹ô”F:”í’eAŠï”F:ƒXƒNƒ‰ƒbƒv
    if(GameController::frame % 2 == 0) {
        if(!Check_Player_EBullet_Collision()) Check_Player_Enemy_Collision();
    } else {
        Check_Player_Scraps_Collision();
    }
}

void CollisionCtrl::DebugDraw() {
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);

    Debug(&GameController::player->collider->GetParameter());

    for(auto pb : GameController::player->bulletVec) {
        Debug(&pb->collider->GetParameter());
    }

    for(auto ev : EnemyCtrl::enemysVec_Ground) {
        for(auto col : ev->colliders) {
            Debug(&col->GetParameter());
        }
    }

    for(auto ev : EnemyCtrl::enemysVec_Air) {
        for(auto col : ev->colliders) {
            Debug(&col->GetParameter());
        }
    }

    for(auto sv : ScrapsCtrl::scrapVec) {
        Debug(&sv->collider->GetParameter());
    }

    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);

    for(auto bullet : EnemyBulletsCtrl::bulletsVec) {
        Debug(&bullet->collider->GetParameter());
    }

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
}

void CollisionCtrl::Check_PBullet_Enemy_Collision() {
    // ‹ó’†“G‚Æ‚Ì”»’è
    if(EnemyCtrl::enemysVec_Air.size() != 0) {
        for(auto PB_itr : GameController::player->bulletVec) {
            if(PB_itr->active) {
                for(auto E_itr : EnemyCtrl::enemysVec_Air) {
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
    if(EnemyCtrl::enemysVec_Ground.size() != 0) {
        for(auto PB_itr : GameController::player->bulletVec) {
            if(PB_itr->active) {
                for(auto E_itr : EnemyCtrl::enemysVec_Ground) {
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
    if(ScrapsCtrl::scrapVec.size() == 0) return;
    for(auto PB_itr : GameController::player->bulletVec) {
        if(PB_itr->bulletType == 1 && PB_itr->active) {
            for(auto S_itr : ScrapsCtrl::scrapVec) {
                if(!S_itr->death && CheckCollision(PB_itr->collider, S_itr->collider)) {
                    if(PB_itr->HitFunc()) {
                        S_itr->Dagame(1);
                        if(S_itr->HP <= 0) GameController::AddScore(10, false);
                    }
                    break;
                }
            }
        }
    }
}

bool CollisionCtrl::Check_Player_Enemy_Collision() {
    for(auto enemy : EnemyCtrl::enemysVec_Air) {
        if(!enemy->onGround) {
            for(auto col : enemy->colliders) {
                if(CheckCollision(GameController::player->collider, col)) {
                    GameController::player->HitFunc();
                    return true;
                }
            }
        }
    }
    return false;
}

bool CollisionCtrl::Check_Player_EBullet_Collision() {
    for(auto eBullet : EnemyBulletsCtrl::bulletsVec) {
        if(!eBullet->death) {
            if(CheckCollision(eBullet->collider, GameController::player->collider)) {
                eBullet->DeathFunc();
                GameController::player->HitFunc();
                return true;
            }
        }
    }
    return false;
}

void CollisionCtrl::Check_Player_Scraps_Collision() {
    for(auto S_itr : ScrapsCtrl::scrapVec) {
        if(!S_itr->death) {
            if(CheckCollision(GameController::player->collider, S_itr->collider)) {
                GameController::player->HitFunc();
                S_itr->hitP = true;
            }
        }
    }
}

void CollisionCtrl::Debug(ColliderParam* param) {
    switch(param->type) {
        case ColliderType::CIRCLE:
            DrawCircle(round(param->centerPos.x), round(param->centerPos.y), param->radius, GetColor(0, 255, 0));
            break;

        case ColliderType::BOX:
            DrawBox(round(param->pos1.x), round(param->pos1.y), round(param->pos2.x), round(param->pos2.y), GetColor(0, 255, 0), TRUE);
            break;

        case ColliderType::LINE:
            DrawLine(round(param->pos1.x), round(param->pos1.y), round(param->pos2.x), round(param->pos2.y), GetColor(0, 255, 0));
            break;
    }
}