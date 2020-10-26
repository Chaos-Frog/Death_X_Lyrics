#include "Player_A.h"
Player_A::Player_A() : Player() {
    playerImgs     = Assets::player01.handle;
    playerImgs_Hit = Assets::player01_Hit.handle;
    speed = SPEED;
}
Player_A::~Player_A(){}


void Player_A::SetShot() {
    if(shotCT == 0) {
        Vector2 p1 = position + Vector2(15, 0);
        Vector2 p2 = position + Vector2(-15, 0);

        // 6-Way
        bulletVec.emplace_back(new P_Bullet(p1, -90 * (M_PI / 180)));
        bulletVec.emplace_back(new P_Bullet(p1, -75 * (M_PI / 180)));
        bulletVec.emplace_back(new P_Bullet(p1, -60 * (M_PI / 180)));
        bulletVec.emplace_back(new P_Bullet(p2, -90 * (M_PI / 180)));
        bulletVec.emplace_back(new P_Bullet(p2, -105 * (M_PI / 180)));
        bulletVec.emplace_back(new P_Bullet(p2, -120 * (M_PI / 180)));

        shotCT = 4;
    }
}

void Player_A::SetMissile() {
    if(missileCT == 0) {
        bulletVec.emplace_back(new P_Missile(position, -M_PI_2));
        missileCT = 12;
    }
}

void Player_A::AnimationBomber() {
    SetFontSize(100);
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<int> dist(-20, 20);
    std::uniform_int_distribution<int> distColor(0, 255);
    DrawString(100 + dist(mt), 260 + dist(mt), "BOMBER!!!", GetColor(distColor(mt), distColor(mt), distColor(mt)));
}

void Player_A::DrawPlane() {
    int x = round(position.x);
    int y = round(position.y);
    if(rotate == 0) {
        DrawGraph(x - (SIZE_X / 2), y - (SIZE_Y / 2) + 10, playerImgs[imgNum], TRUE);
        if(frame % 2 == 0) {
            imgNum++;
            if(imgNum >= 4) imgNum = 0;
        }
    } else if(rotate > 0) {
        if(rotate < 5) {
            imgNum = rotate + 3;
        } else {
            if(frame % 2 == 0) {
                imgNum++;
                if(imgNum < 8 || imgNum >= 12) imgNum = 8;
            }
        }
        DrawGraph(x - (SIZE_X / 2), y - (SIZE_Y / 2) + 10, playerImgs[imgNum], TRUE);
    } else if(rotate < 0) {
        if(rotate > -5) {
            imgNum = abs(rotate) + 3;
        } else {
            if(frame % 2 == 0) {
                imgNum++;
                if(imgNum < 8 || imgNum >= 12) imgNum = 8;
            }
        }
        DrawTurnGraph(x - (SIZE_X / 2), y - (SIZE_Y / 2) + 10, playerImgs[imgNum], TRUE);
    }

    // TEST
    if(hitCT > 0) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
        if(rotate >= 0) DrawGraph(x - (SIZE_X / 2), y - (SIZE_Y / 2) + 10, playerImgs_Hit[imgNum], TRUE);
        else            DrawTurnGraph(x - (SIZE_X / 2), y - (SIZE_Y / 2) + 10, playerImgs_Hit[imgNum], TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        hitCT--;
    }
}

void Player_A::HitFunc() {
    hitCT = 5;
}