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
                            if(CollisionCheck(PB_itr->collider, enemyCol)) {
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
                        if(CollisionCheck(PB_itr->collider, S_itr->collider)) {
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
                if(CollisionCheck(player->collider, col)) {
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
            if(CollisionCheck(eBullet->collider, player->collider)) {
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
            if(CollisionCheck(player->collider, S_itr->collider)) {
                player->HitFunc();
                S_itr->hitP = true;
            }
        }
    }
}

bool CollisionCtrl::CollisionCheck(const Collider* c1, const Collider* c2) {
    if(c1->type == CIRCLE) {
        if(c2->type == CIRCLE) {
            return CC_Collider(&c1->position, c1->radius, &c2->position, c2->radius);
        } else if(c2->type == BOX) {
            return CB_Collider(&c1->position, c1->radius, &c2->pos1, &c2->pos2);
        } else if(c2->type == LINE) {
            return CL_Collider(&c1->position, c1->radius, &c2->pos1, &c2->pos2);
        }
    } else if(c1->type == BOX) {
        if(c2->type == CIRCLE) {
            return CB_Collider(&c2->position, c2->radius, &c1->pos1, &c1->pos2);
        } else if(c2->type == BOX) {
            return BB_Collider(&c1->pos1, &c1->pos2, &c2->pos1, &c2->pos2);
        } else if(c2->type == LINE){
            return false;
        }
    } else if(c1->type == LINE) {
        if(c2->type == CIRCLE) {
            return CL_Collider(&c2->position, c2->radius, &c1->pos1, &c1->pos2);
        } else if(c2->type == BOX) {
            return false;
        } else if(c2->type == LINE) {
            return false;
        }
    } else {
        return false;
    }
}

bool CollisionCtrl::CC_Collider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2) {
    const Vector2 dif = *v2 - *v1;
    const double radius = cr1 + cr2;
    return pow(dif.x, 2) + pow(dif.y, 2) <= pow(radius, 2);
}

bool CollisionCtrl::BB_Collider(const Vector2* v1, const Vector2* v2, const Vector2* v3, const Vector2* v4) {
    if(v1->x <= v4->x && v2->x >= v3->x && v1->y <= v4->y && v2->y >= v3->y) {
        return true;
    } else {
        return false;
    }
}

bool CollisionCtrl::CB_Collider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2) {
    Vector2 nearest;
    if(v->x < v1->x)      nearest.x = v1->x;
    else if(v->x > v2->x) nearest.x = v2->x;
    else                  nearest.x = v->x;

    if(v->y < v1->y)      nearest.y = v1->y;
    else if(v->y > v2->y) nearest.y = v2->y;
    else                  nearest.y = v->y;

    return CC_Collider(v, cr, &nearest, 0.0f);
}

bool CollisionCtrl::CL_Collider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2) {
    if(CC_Collider(v, cr, lv1, 0) || CC_Collider(v, cr, lv2, 0)) return true;

    const Vector2 lineV = *lv2 - *lv1;
    const Vector2 lineCV = *v - *lv1;
    Vector2 proj;
    const double dot = pow(lineV.x, 2) + pow(lineV.y, 2);
    if(dot < 0) {
        const double dotP = (lineV.x * lineCV.x) + (lineV.y * lineCV.y);
        proj = lineV * (dotP/dot);
    } else {
        proj = lineCV;
    }
    const Vector2 nearest = *lv1 + proj;

    return CC_Collider(v, cr, &nearest, 0) &&
           pow(proj.x, 2) + pow(proj.y, 2) <= pow(lineV.x, 2) + pow(lineV.y, 2) &&
           0 <= (proj.x * lineV.x) + (proj.y * lineV.y);

}