#include "Player.h"
Player::Player(Assets* as) {
    imgs = as;

    position = Vector2(320, 600);
    collider = new Circle_C(&position, Vector2(0, 0), CORE_RADIUS);
    speed = 0;

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
    bulletVec.clear();
    delete collider;
}

void Player::Update() {
    Moving();
    collider->Update();
    Shot();
    Bomber();
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
        if(position.y > MOVE_Y_MIN) {
            position.y -= speed * coe;
            if(position.y < MOVE_Y_MIN) position.y = MOVE_Y_MIN;
        }
    }
    if(CheckHitKey(KEY_INPUT_S) == 1) {
        if(position.y < MOVE_Y_MAX) {
            position.y += speed * coe;
            if(position.y > MOVE_Y_MAX) position.y = MOVE_Y_MAX;
        }
    }
    if(CheckHitKey(KEY_INPUT_D) == 1) {
        if(position.x < MOVE_X_MAX) {
            position.x += speed * coe;
            if(position.x > MOVE_X_MAX) position.x = MOVE_X_MAX;
        }
        if(rotate < 5) rotate++;
    }
    if(CheckHitKey(KEY_INPUT_A) == 1) {
        if(position.x > MOVE_X_MIN) {
            position.x -= speed * coe;
            if(position.x < MOVE_X_MIN) position.x = MOVE_X_MIN;
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
        SetMissile();
    } else if(CheckHitKey(KEY_INPUT_L)) {
        SetShot();
    }
    if(shotCT > 0)    shotCT--;
    if(missileCT > 0) missileCT--;

    for(auto itr = bulletVec.begin(); itr != bulletVec.end();) {
        if((*itr)->Update()) {
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
            bomberCT = 150;
        }
    }

    if(bomberCT > 0) {
        bomberCT--;
        if(bomberCT == 0) bomber = false;
    }
    
    if(bomber) AnimationBomber();
}

void Player::DrawBullets() {
    for(auto bullet : bulletVec) {
        bullet->Draw();
    }
}

void Player::SetShot(){}
void Player::SetMissile(){}
void Player::AnimationBomber(){}
void Player::DrawPlane() {}
void Player::HitFunc() {}