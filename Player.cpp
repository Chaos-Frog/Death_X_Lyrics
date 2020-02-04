#include "Player.h"
Player::Player() {
    position = new Vector2(640, 600);
    LoadDivGraph("Assets/Heli.png", 12, 4, 3, SIZE_X, SIZE_Y, playerImgs);
    bulletImage = LoadGraph("Assets/PlayerBullet.png");
    frame = 1;
    imgNum = 0;
    rotate = 0;
}

void Player::Update() {
    Moving();
    Shot();
    frame++;
}

void Player::Moving() {
    // ˆÚ“®‘€ì
    double coe;
    if((CheckHitKey(KEY_INPUT_W) ^ CheckHitKey(KEY_INPUT_S)) & (CheckHitKey(KEY_INPUT_D) ^ CheckHitKey(KEY_INPUT_A))) {
        coe = 0.71;
    } else {
        coe = 1;
    }

    if(CheckHitKey(KEY_INPUT_W) == 1) {
        if(position->y > (double)(0+SIZE_Y/2)) {
            position->y -= SPEED * coe;
            if(position->y < (double)(0+SIZE_Y/2)) position->y = (double)(0+SIZE_Y/2);
        }
    }
    if(CheckHitKey(KEY_INPUT_S) == 1) {
        if(position->y < (double)(720-SIZE_Y/2)) {
            position->y += SPEED * coe;
            if(position->y > (double)(720-SIZE_Y/2)) position->y = (double)(720-SIZE_Y/2);
        }
    }
    if(CheckHitKey(KEY_INPUT_D) == 1) {
        if(position->x < (double)(960-SIZE_X/2)) {
            position->x += SPEED * coe;
            if(position->x > (double)(960-SIZE_X/2)) position->x = (double)(960-SIZE_X/2);
        }
        if(rotate < 5) rotate++;
    }
    if(CheckHitKey(KEY_INPUT_A) == 1) {
        if(position->x > (double)(320 +SIZE_Y/2)) {
            position->x -= SPEED * coe;
            if(position->x < (double)(320 +SIZE_X/2)) position->x = (double)(320+SIZE_X/2);
        }
        if(rotate > -5) rotate--;
    }

    if(!(CheckHitKey(KEY_INPUT_D) ^ CheckHitKey(KEY_INPUT_A))) {
        if(rotate > 0)      rotate--;
        else if(rotate < 0) rotate++;
    }

    // •`‰æ
    if(rotate == 0) {
        DrawGraph(round(position->x) - (SIZE_X / 2), round(position->y) - (SIZE_Y / 2), playerImgs[imgNum], TRUE);
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
        DrawGraph(round(position->x) - (SIZE_X / 2), round(position->y) - (SIZE_Y / 2), playerImgs[imgNum], TRUE);
    } else if(rotate < 0) {
        if(rotate > -5) {
            imgNum = abs(rotate) + 3;
        } else {
            if(frame % 2 == 0) {
                imgNum++;
                if(imgNum < 8 || imgNum >= 12) imgNum = 8;
            }
        }
        DrawTurnGraph(round(position->x) - (SIZE_X / 2), round(position->y) - (SIZE_Y / 2), playerImgs[imgNum], TRUE);
    }
}

void Player::Shot() {
    if(CheckHitKey(KEY_INPUT_J)) {
        PlayerBullet* pb = new PlayerBullet(0, position, -M_PI_2, &bulletImage);
        bulletVec.emplace_back(pb);
    }

    for(int i=0; i<bulletVec.size(); i++) {
        if(!bulletVec[i]->MoveBullet()) {
            delete bulletVec[i];
            bulletVec.erase(bulletVec.begin()+i);
        }
    }
}