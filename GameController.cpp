#include "GameController.h"
#include <random>
GameController::GameController(Assets* img) {
    player = new Player(img);
    ebc = new EnemyBulletsCtrl(img);
    sc = new ScrapsCtrl(img, this);
    ec = new EnemyCtrl(img, player, ebc, sc);
    colCtrl = new CollisionCtrl(this, player, ec, ebc, sc);
    
    frame = 1;
    score = 0;
    scrapMagni = 10;
    scrapMagniGage = 0;
}
GameController::~GameController() {
    delete player;
    delete ec;
    delete ebc;
    delete sc;
    delete colCtrl;
}

void GameController::Update() {
    DrawBox(0, 0, 640, 720, GetColor(150, 150, 150), TRUE);

    if(frame == 1 || ec->enemysVec.size() <= 0) {
        //ec->SetEnemy(1, new Vector2(520, -130), 3, 2);
        //ec->SetEnemy(1, new Vector2(420, -80), 2, 1);
        //ec->SetEnemy(2, new Vector2(320, -130), 2, 1);
        //ec->SetEnemy(1, new Vector2(220, -80), 2, 1);
        //ec->SetEnemy(1, new Vector2(120, -130), 3, 2);
        ec->SetEnemy(2, new Vector2(320, 0), 2, 1);
    }
    
    player->Update();
    ec->Update();
    ebc->Update();
    sc->Update();

    if(scrapMagniGage > 0) scrapMagniGage--;

    if(frame%2 == 0) colCtrl->Update();

    if(player->bomber) ebc->DeleteAllBullet();

    ebc->Draw();
    sc->Draw();
    ec->Draw();
    player->DrawBullets();

    /* Collider Debug */
    if(false) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        player->collider->DebugDraw();
        for(auto pb : player->bulletVec) {
            pb->collider->DebugDraw();
        }
        for(auto ev : ec->enemysVec) {
            for(auto col : ev->colliders) {
                col->DebugDraw();
            }
        }
        for(auto sv : sc->scrapVec) {
            sv->collider->DebugDraw();
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
        for(auto bullet : ebc->bulletsVec) {
            bullet->collider->DebugDraw();
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
    }

    frame++;
}

void GameController::Update_UI() {
    DrawBox(0, 0, 1280, 720, GetColor(50, 50, 50), TRUE);

    /* Debug */
    int bnum = ebc->bulletsVec.size();
    std::string str = "BulletsNum:" + std::to_string(bnum);
    std::string score_str = "Score:" + std::to_string(score);
    std::string scmag_str = "ScrapMagnification:" + std::to_string((int)scrapMagni / 10) + "." + std::to_string((int)scrapMagni % 10);
    std::string scmag_Gage;
    for(int i = 0; i < ceil(scrapMagniGage / 10); i++) {
        scmag_Gage += "¡";
    }
    std::string scmag_Gage_BG = "¡¡¡¡¡¡¡¡¡¡";

    SetFontSize(20);
    DrawString(10, 10, str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 35, score_str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 60, scmag_str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 80, scmag_Gage_BG.c_str(), GetColor(0, 80, 0));
    DrawString(10, 80, scmag_Gage.c_str(), GetColor(0, 200, 0));
}