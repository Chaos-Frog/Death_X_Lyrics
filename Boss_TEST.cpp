#include "Boss_TEST.h"
#include "GameController.h"

Boss_TEST::Boss_TEST(GameController* gc) : Boss(gc) {
    HP = 2000;
    phase = 0;
    position = Vector2(GAME_WINDOW_XSIZE / 2.0, GAME_WINDOW_YSIZE / 3.0);
    colliders.emplace_back(new Box_C(&position, Vector2(0, 0), 240, 300));

    destroyParts = 0;

    for(int i = 0; i < 20; i++) {
        bossParts[i].HP = 60;
        int x = i % 4;
        int y = i / 4;
        bossParts[i].relativePos = Vector2((x*60.0) - 90.0, (y*60.0) - 120.0);
        bossParts[i].position = position + bossParts[i].relativePos;
        bossParts[i].col = new Box_C(&bossParts[i].position, Vector2(0, 0), 60, 60);
    }
}

bool Boss_TEST::Update() {
    switch(phase) {
        case 0:
            if(destroyParts == 20) {
                phase = 1;
            } else {
                for(auto itr : bossParts) {
                    itr.position = position + itr.relativePos;
                }
            }
            break;

        case 1:
            break;
    }
    return true;
}

void Boss_TEST::Draw() {
    if(HP > 0) {
        DrawBox(position.x - 120,
                position.y - 150,
                position.x + 120,
                position.y + 150,
                GetColor(0, 160, 0), TRUE);
    }

    for(auto itr : bossParts) {
        if(itr.HP > 0) {
            DrawBox(itr.position.x - 30, itr.position.y - 30,
                    itr.position.x + 30, itr.position.y + 30,
                    GetColor(0, 40, 0), TRUE);
        }
    }
}

bool Boss_TEST::DeathFunc() {
    return true;
}

void Boss_TEST::CheckCol_Boss_PBullets() {
    for(auto PB_itr : gameController->player->bulletVec) {
        if(PB_itr->active) {
            switch(phase) {
                case 0:
                    for(int i = 0; i < 20; i++) {
                        if(bossParts[i].HP > 0 && CheckCollision(PB_itr->collider, bossParts[i].col)) {
                            if(PB_itr->HitFunc()) {
                                bossParts[i].HP -= 1;
                                HP--;
                            }
                            if(bossParts[i].HP <= 0) {
                                gameController->scrCtrl->SetScrap(1, bossParts[i].position, 4);
                                gameController->score += 10000;
                                destroyParts++;
                            }
                        }
                    }
                    break;

                case 1:
                    for(auto col : colliders) {
                        if(HP > 0 && CheckCollision(PB_itr->collider, col)) {
                            if(PB_itr->HitFunc()) {
                                HP--;
                            }
                            if(HP <= 0) {
                                gameController->score += 100000;
                            }
                            break;
                        }
                    }
                    break;
            }
        }
    }
}

void Boss_TEST::CheckCol_Boss_Player() {
    // ínè„ìGÇ»ÇÁèàóùÇ»Çµ
}