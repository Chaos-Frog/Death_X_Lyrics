#include "Player.h"
Player::Player(Assets* img) {
    imgs = img;
    playerImgs = imgs->player01;
    playerImgs_Hit = imgs->player01_Hit;

    position = Vector2(320, 600);
    collider = new Circle_C(&position, Vector2(0, 0), CORE_RADIUS);
    frame = 1;
    imgNum = 0;
    rotate = 0;
    shotCT = 0;
    missileCT = 0;
    bomber = false;
    bomberCT = 0;
    hitCT = 0;
}

Player::~Player() {
    for(int i = 0; i < bulletVec.size(); i++) {
        bulletVec.erase(bulletVec.begin() + i);
    }
    delete collider;
}

void Player::Update() {
    Moving();
    collider->Update();
    Shot();
    Bomber();
    Draw();
    frame++;
}

void Player::Moving() {
    double coe;
    if(CheckHitKey(KEY_INPUT_J)) coe = 0.7;
    else                         coe = 1.0;
    if((CheckHitKey(KEY_INPUT_W) ^ CheckHitKey(KEY_INPUT_S)) & (CheckHitKey(KEY_INPUT_D) ^ CheckHitKey(KEY_INPUT_A))) {
        coe *= 0.71;
    }

    if(CheckHitKey(KEY_INPUT_W) == 1) {
        if(position.y > (double)(SIZE_Y/2)) {
            position.y -= SPEED * coe;
            if(position.y < (double)(SIZE_Y/2)) position.y = (double)(SIZE_Y/2);
        }
    }
    if(CheckHitKey(KEY_INPUT_S) == 1) {
        if(position.y < (double)(GAME_WINDOW_YSIZE - SIZE_Y/2)) {
            position.y += SPEED * coe;
            if(position.y > (double)(GAME_WINDOW_YSIZE - SIZE_Y/2)) position.y = (double)(GAME_WINDOW_YSIZE - SIZE_Y/2);
        }
    }
    if(CheckHitKey(KEY_INPUT_D) == 1) {
        if(position.x < (double)(GAME_WINDOW_XSIZE - SIZE_X/2)) {
            position.x += SPEED * coe;
            if(position.x > (double)(GAME_WINDOW_XSIZE - SIZE_X/2)) position.x = (double)(GAME_WINDOW_XSIZE - SIZE_X/2);
        }
        if(rotate < 5) rotate++;
    }
    if(CheckHitKey(KEY_INPUT_A) == 1) {
        if(position.x > (double)(SIZE_X/2)) {
            position.x -= SPEED * coe;
            if(position.x < (double)(SIZE_X/2)) position.x = (double)(SIZE_X/2);
        }
        if(rotate > -5) rotate--;
    }

    if(!(CheckHitKey(KEY_INPUT_D) ^ CheckHitKey(KEY_INPUT_A))) {
        if(rotate > 0)      rotate--;
        else if(rotate < 0) rotate++;
    }
}

void Player::Shot() {
    if(CheckHitKey(KEY_INPUT_J)) {
        if(missileCT <= 0) {
            bulletVec.emplace_back(new P_Missile(&position, -M_PI_2, imgs));
            missileCT = 12;
        }
    } else if(CheckHitKey(KEY_INPUT_L)) {
        if(shotCT <= 0) {
            Vector2 p1 = position + Vector2(15, 0);
            Vector2 p2 = position + Vector2(-15, 0);
            bulletVec.emplace_back(new P_Bullet(&p1, -90 * (M_PI / 180), imgs));
            bulletVec.emplace_back(new P_Bullet(&p1, -75 * (M_PI / 180), imgs));
            bulletVec.emplace_back(new P_Bullet(&p1, -60 * (M_PI / 180), imgs));
            bulletVec.emplace_back(new P_Bullet(&p2, -90 * (M_PI / 180), imgs));
            bulletVec.emplace_back(new P_Bullet(&p2, -105 * (M_PI / 180), imgs));
            bulletVec.emplace_back(new P_Bullet(&p2, -120 * (M_PI / 180), imgs));
            shotCT = 6;
        }
    }
    if(shotCT > 0) shotCT--;
    if(missileCT > 0) missileCT--;

    auto itr = bulletVec.begin();
    while(itr != bulletVec.end()) {
        if((*itr)->MoveBullet()) {
            itr++;
        } else {
            itr = bulletVec.erase(itr);
        }
    }
}

void Player::Bomber() {
    if(CheckHitKey(KEY_INPUT_K)) {
        if(!bomber) {
            bomber = true;
            bomberCT = 100;
        }
    }

    if(bomberCT > 0) {
        bomberCT--;
        if(bomberCT == 0) bomber = false;
    }
    
    // TEST
    if(bomber) {
        SetFontSize(100);
        std::random_device rnd;
        std::mt19937 mt(rnd());
        std::uniform_int_distribution<int> dist(-20, 20);
        std::uniform_int_distribution<int> distColor(0, 255);
        DrawString(100 + dist(mt), 260 + dist(mt), "BOMBER!!!", GetColor(distColor(mt), distColor(mt), distColor(mt)));
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
    if(hitCT > 0) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
        if(rotate >= 0) DrawGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs_Hit[imgNum], TRUE);
        else            DrawTurnGraph(x - (SIZE_X/2), y - (SIZE_Y/2) + 10, playerImgs_Hit[imgNum], TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        hitCT--;
    }
}

void Player::DrawBullets() {
    for(auto bullet : bulletVec) {
        bullet->Draw();
    }
}

void Player::HitFunc() {
    hitCT = 5;
}