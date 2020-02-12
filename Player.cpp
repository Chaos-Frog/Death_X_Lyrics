#include "Player.h"
Player::Player(Assets* img) {
    position = Vector2(640, 600);
    imgs = img;
    playerImgs = imgs->player01;
    playerImgs_ADD = imgs->player01_ADD;
    frame = 1;
    imgNum = 0;
    rotate = 0;
    shotCT = 0;
    hitCT = 0;
}

Player::~Player() {
    for(int i = 0; i < bulletVec.size(); i++) {
        bulletVec.erase(bulletVec.begin() + i);
    }
}

void Player::Update() {
    Moving();
    Shot();
    Draw();
    frame++;
}

void Player::Moving() {
    double coe;
    if((CheckHitKey(KEY_INPUT_W) ^ CheckHitKey(KEY_INPUT_S)) & (CheckHitKey(KEY_INPUT_D) ^ CheckHitKey(KEY_INPUT_A))) {
        coe = 0.71;
    } else {
        coe = 1;
    }

    if(CheckHitKey(KEY_INPUT_W) == 1) {
        if(position.y > (double)(0+SIZE_Y/2)) {
            position.y -= SPEED * coe;
            if(position.y < (double)(0+SIZE_Y/2)) position.y = (double)(0+SIZE_Y/2);
        }
    }
    if(CheckHitKey(KEY_INPUT_S) == 1) {
        if(position.y < (double)(720-SIZE_Y/2)) {
            position.y += SPEED * coe;
            if(position.y > (double)(720-SIZE_Y/2)) position.y = (double)(720-SIZE_Y/2);
        }
    }
    if(CheckHitKey(KEY_INPUT_D) == 1) {
        if(position.x < (double)(960-SIZE_X/2)) {
            position.x += SPEED * coe;
            if(position.x > (double)(960-SIZE_X/2)) position.x = (double)(960-SIZE_X/2);
        }
        if(rotate < 5) rotate++;
    }
    if(CheckHitKey(KEY_INPUT_A) == 1) {
        if(position.x > (double)(320 +SIZE_Y/2)) {
            position.x -= SPEED * coe;
            if(position.x < (double)(320 +SIZE_X/2)) position.x = (double)(320+SIZE_X/2);
        }
        if(rotate > -5) rotate--;
    }

    if(!(CheckHitKey(KEY_INPUT_D) ^ CheckHitKey(KEY_INPUT_A))) {
        if(rotate > 0)      rotate--;
        else if(rotate < 0) rotate++;
    }
}

void Player::Shot() {
    if(shotCT > 0) {
        shotCT--;
    } else {
        if(CheckHitKey(KEY_INPUT_J)) {
            bulletVec.emplace_back(PlayerBullet(0, &position, -M_PI_2, &imgs->playerBullet01));
            shotCT = 4;
        }
    }

    auto itr = bulletVec.begin();
    while(itr != bulletVec.end()) {
        if(itr->MoveBullet()) {
            itr++;
        } else {
            itr = bulletVec.erase(itr);
        }
    }
}

void Player::Draw() {
    int x = round(position.x); 
    int y = round(position.y);
    if(rotate == 0) {
        DrawGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs[imgNum], TRUE);
        if(frame%2 == 0) {
            imgNum++;
            if(imgNum >= 4) imgNum = 0;
        }
    } else if(rotate > 0) {
        if(rotate < 5) {
            imgNum = rotate + 3;
        } else {
            if(frame%2 == 0) {
                imgNum++;
                if(imgNum < 8 || imgNum >= 12) imgNum = 8;
            }
        }
        DrawGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs[imgNum], TRUE);
    } else if(rotate < 0) {
        if(rotate > -5) {
            imgNum = abs(rotate) + 3;
        } else {
            if(frame%2 == 0) {
                imgNum++;
                if(imgNum < 8 || imgNum >= 12) imgNum = 8;
            }
        }
        DrawTurnGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs[imgNum], TRUE);
    }

    // TEST
    DrawCircleAA(x, y, CORE_RADIUS, 64, GetColor(0, 255, 0));
    if(hitCT > 0) {
        SetDrawBlendMode(DX_BLENDMODE_ADD, 200);
        if(rotate >= 0) DrawGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs_ADD[imgNum], TRUE);
        else            DrawTurnGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs_ADD[imgNum], TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        hitCT--;
    }
}