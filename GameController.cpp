#include "GameController.h"
#include "EnemyCtrl.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"
#include "EffectsCtrl.h"
#include "CollisionCtrl.h"

#define GAME_DEBUG_MODE true

unsigned long GameController::score          = 0;
int           GameController::frame          = 1;
int           GameController::scrapMagni     = 0;
int           GameController::scrapMagniGage = 0;
StageBase*    GameController::stage          = nullptr;
Player*       GameController::player         = nullptr;

void GameController::Init() {
    player = new Player_A();
    stage = new StageBase(0);

    EnemyCtrl::Init();
    EnemyBulletsCtrl::Init();
    ScrapsCtrl::Init();
    EffectsCtrl::Init();
}

void GameController::Init(int stageNum) {
    switch(stageNum) {
        case 1:
            // stage = Stage_1();
            break;

        default:
            break;
    }
}

void GameController::Update() {
    if(CheckHitKey(KEY_INPUT_ESCAPE)) {
        SceneManager::ChangeScene(SCENE_MENU);
        return;
    }

    /*  StageTEST  */
    DrawBox(0, 0, 640, 720, GetColor(150, 150, 150), TRUE);
    if(EnemyCtrl::enemysVec_Air.size() <= 0) {
        EnemyCtrl::SetEnemy(1, new Vector2(520, -130), 2, 2);
        EnemyCtrl::SetEnemy(1, new Vector2(420, -80), 2, 1);
        EnemyCtrl::SetEnemy(2, new Vector2(320, -130), 2, 1);
        EnemyCtrl::SetEnemy(1, new Vector2(220, -80), 2, 1);
        EnemyCtrl::SetEnemy(1, new Vector2(120, -130), 2, 2);
    }

    /*if(frame % 40 == 0 && eneCtrl->enemysVec_Ground.size() < 5) {
        EnemyCtrl::SetEnemy(101, new Vector2(320, -60), 2, 1);
    }*/
    /*--StageTest--*/
    
    player->Update();
    EnemyCtrl::Update();
    EnemyBulletsCtrl::Update();
    ScrapsCtrl::Update();
    EffectsCtrl::Update();

    if(scrapMagniGage > 0) scrapMagniGage--;
    if(player->bomber) EnemyBulletsCtrl::DeleteAllBullet();

    CollisionCtrl::Update();

    /* •`‰æˆ— */
    EnemyCtrl::Draw();
    EffectsCtrl::Draw();
    ScrapsCtrl::Draw();
    player->DrawPlane();
    player->DrawBullets();
    EnemyBulletsCtrl::Draw();

    /* Debug - Collider‰ÂŽ‹‰»*/
    if(GAME_DEBUG_MODE) {
        CollisionCtrl::DebugDraw();
    }

    frame++;
}

void GameController::Update_UI() {
    DrawBox(0, 0, 1280, 720, GetColor(50, 50, 50), TRUE);

    /* Debug•\Ž¦ */
    int bnum = EnemyBulletsCtrl::bulletsVec.size();
    std::string str = "BulletsNum:" + std::to_string(bnum);
    std::string score_str = "Score:" + std::to_string(score);
    std::string scmag_str = "ScrapMagnification:" + std::to_string((int)scrapMagni / 10) + "." + std::to_string((int)scrapMagni % 10);
    std::string scmag_Gage;
    for(int i = 0; i < ceil((double)scrapMagniGage / 10.0); i++) {
        scmag_Gage += "¡";
    }
    std::string scmag_Gage_BG = "¡¡¡¡¡¡¡¡¡¡" + std::to_string(scrapMagniGage);

    SetFontSize(20);
    DrawString(10, 10, str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 35, score_str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 60, scmag_str.c_str(), GetColor(0, 200, 0));
    DrawString(10, 80, scmag_Gage_BG.c_str(), GetColor(0, 80, 0));
    DrawString(10, 80, scmag_Gage.c_str(), GetColor(0, 200, 0));
}

void GameController::AddScore(int s, bool magni) {
    if(magni) score += s * ((double)scrapMagni / 10.0);
    else      score += s;
}