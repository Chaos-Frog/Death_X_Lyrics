#include "CollisionCtrl.h"
CollisionCtrl::CollisionCtrl(Player* pl, EnemyCtrl* ec, EnemyBulletsCtrl* ebc) {
    player = pl;
    enemyCtrl = ec;
    EBC = ebc;
}

CollisionCtrl::~CollisionCtrl() {}

void CollisionCtrl::Update() {
    // PlayerBullets & Enemy
    auto PB_itr = player->bulletVec.begin();
    while (PB_itr != player->bulletVec.end()) {
        for(auto &E_itr : enemyCtrl->enemysVec) {
            if(CC_Colider(&PB_itr->position, 10, &E_itr->position, 25)) {
                PB_itr = player->bulletVec.erase(PB_itr);
            } else {
                PB_itr++;
            }
        }
    }
    // Player & EnemyBullets
    auto EBitr = EBC->bulletsVec.begin();
    while(EBitr != EBC->bulletsVec.end()) {
        switch(EBitr->bulletType) {
            case 1:
            case 2:
                if(CC_Colider(&player->position, CORE_RADIUS, &EBitr->position, EBitr->radius)) {
                    EBitr = EBC->bulletsVec.erase(EBitr);
                    player->hitCT = 5;
                } else {
                    EBitr++;
                }
            default:
                break;
        }
    }
}

bool CollisionCtrl::CC_Colider(const Vector2* v1, const double cr1, const Vector2* v2, const double cr2) {
    const Vector2 dif = *v2 - *v1;
    const double radius = cr1 + cr2;
    return pow(dif.x, 2) + pow(dif.y, 2) <= pow(radius, 2);
}

bool CollisionCtrl::CB_Colider(const Vector2* v, const double cr, const Vector2* v1, const Vector2* v2) {
    Vector2 nearest;
    if(v->x < v1->x)      nearest.x = v1->x;
    else if(v->x > v2->x) nearest.x = v2->x;
    else                  nearest.x = v->x;

    if(v->y < v1->y)      nearest.x = v1->y;
    else if(v->y > v2->y) nearest.x = v2->y;
    else                  nearest.x = v->y;

    return CC_Colider(v, cr, &nearest, 0);
}

bool CollisionCtrl::CL_Colider(const Vector2* v, const double cr, const Vector2* lv1, const Vector2* lv2) {
    if(CC_Colider(v, cr, lv1, 0) || CC_Colider(v, cr, lv2, 0)) return true;

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

    return CC_Colider(v, cr, &nearest, 0) &&
           pow(proj.x, 2) + pow(proj.y, 2) <= pow(lineV.x, 2) + pow(lineV.y, 2) &&
           0 <= (proj.x * lineV.x) + (proj.y * lineV.y);

}