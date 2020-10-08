#include "GameController.h"

GameController::GameController() {
    stage    = new StageBase(this, 0);
    player   = new Player_A();
    eneCtrl  = new EnemyCtrl(this);
    ebulCtrl = new EnemyBulletsCtrl();
    scrCtrl  = new ScrapsCtrl(this);
    colCtrl  = new CollisionCtrl(this);
    
    frame = 1;
    score = 0;
    scrapMagni = 10;
    scrapMagniGage = 0;
}
GameController::~GameController() {
    delete stage;
    delete player;
    delete eneCtrl;
    delete ebulCtrl;
    delete scrCtrl;
    delete colCtrl;
}

void GameController::Update() {
    if(CheckHitKey(KEY_INPUT_ESCAPE)) {
        SceneManager::ChangeScene(SCENE_MENU);
        return;
    }

    /*  StageTEST  */
    DrawBox(0, 0, 640, 720, GetColor(150, 150, 150), TRUE);
    if(frame == 1 || eneCtrl->enemysVec_Air.size() <= 0) {
        eneCtrl->SetEnemy(1, new Vector2(520, -130), 2, 2);
        eneCtrl->SetEnemy(1, new Vector2(420, -80), 2, 1);
        eneCtrl->SetEnemy(2, new Vector2(320, -130), 2, 1);
        eneCtrl->SetEnemy(1, new Vector2(220, -80), 2, 1);
        eneCtrl->SetEnemy(1, new Vector2(120, -130), 2, 2);
    }

    if(frame % 40 == 0 && eneCtrl->enemysVec_Ground.size() < 5) {
        eneCtrl->SetEnemy(101, new Vector2(320, -60), 2, 1);
    }
    /*--StageTest--*/
    
    player->Update();
    eneCtrl->Update();
    ebulCtrl->Update();
    scrCtrl->Update();

    if(scrapMagniGage > 0) scrapMagniGage--;
    if(player->bomber) ebulCtrl->DeleteAllBullet();

    colCtrl->Update();

    /* `ζ */
    scrCtrl->Draw();
    eneCtrl->Draw();
    player->DrawPlane();
    player->DrawBullets();
    ebulCtrl->Draw();

    /* Debug - ColliderΒ»*/
    if(false) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        player->collider->DebugDraw();
        for(auto pb : player->bulletVec) {
            pb->collider->DebugDraw();
        }
        for(auto ev : eneCtrl->enemysVec_Ground) {
            for(auto col : ev->colliders) {
                col->DebugDraw();
            }
        }
        for(auto ev : eneCtrl->enemysVec_Air) {
            for(auto col : ev->colliders) {
                col->DebugDraw();
            }
        }
        for(auto sv : scrCtrl->scrapVec) {
            sv->collider->DebugDraw();
        }
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
        for(auto bullet : ebulCtrl->bulletsVec) {
            bullet->collider->DebugDraw();
        }
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
    }

    frame++;
}

void GameController::Update_UI() {
    DrawBox(0, 0, 1280, 720, GetColor(50, 50, 50), TRUE);

    /* Debug\¦ */
    int bnum = ebulCtrl->bulletsVec.size();
    std::string str = "BulletsNum:" + std::to_string(bnum);
    std::string score_str = "Score:" + std::to_string(score);
    std::string scmag_str = "ScrapMagnification:" + std::to_string((int)scrapMagni / 10) + "." + std::to_string((int)scrapMagni % 10);
    std::string scmag_Gage;
    for(int i = 0; i < ceil((double)scrapMagniGage / 10.0); i++) {
        scmag_Gage += "‘";
    }
    std::string scmag_Gage_BG = "‘‘‘‘‘‘‘‘‘‘" + std::to_string(scrapMagniGage);

    SetFontSize(20);
    DrawString(10, 10, str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 35, score_str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 60, scmag_str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 80, scmag_Gage_BG.c_str(), GetColor(0, 80, 0));
    DrawString(10, 80, scmag_Gage.c_str(), GetColor(0, 200, 0));
}

void GameController::AddScore(int s, bool magni) {
    if(magni) score += s * (scrapMagni/10);
    else      score += s;
}