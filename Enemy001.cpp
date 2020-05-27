#include "Enemy001.h"
Enemy001::Enemy001(Vector2* pos, int mp, int dp, int* img, Player* pla, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) : Enemy(1, pos, 10, mp, dp, pla, ebc, sc) {
	image = img;
	imgNum = 0;
	first = position;
	angle = 0.0f;

	colliders.emplace_back(new Circle_C(&position, Vector2(0, 0), 25));
}

void Enemy001::Update() {
	Moving();
	Draw();
	Danmaku();

	for(auto col : colliders) {
		col->Update();
	}

	frame++;
}

void Enemy001::Moving() {
	switch(movePatern) {
		case 1:
			// TEST
			if(frame < 60) {
				double t = (double)frame / 60.0;
				position.x = (640 - first.x) * t + first.x;
				position.y = (200 - first.y) * t + first.y;
			} else if(frame >= 60) {
				if(frame == 60) first = Vector2(640, 200);
				position.x = sin((frame-60) * (2 * (M_PI / 180))) * 160 + first.x;
				position.y = sin((frame-60) * (4 * (M_PI / 180))) * 80 + first.y;
			}
			break;
		case 2:
			if(frame < 60) {
				double t = (double)frame / 60.0;
				position.y = (200.0 * t) + first.y;
			}
			break;
		case 3:
			if(frame < 60) {
				double t = (double)frame / 60.0;
				position.y = (200.0 * t) + first.y;
			} else {
				double a = TargetPlayerAngle() - 90;
				if(a > angle) {
					if(a - angle >= 5.0f) angle += 5.0f;
					else                  angle = a;
				} else if(a < angle) {
					if(angle - a >= 5.0f) angle -= 5.0f;
					else                  angle = a;
				}
			}
			break;
		default:
			break;
	}
}


void Enemy001::Danmaku() {
	switch(danmakuPatern) {
		case 1:
			// TEST
			if(frame >= 120 && frame % 120 == 0) {
				EBC->SetEnemyBullet(1, &position, 2, 90, 0.6);
			}
			break;
		case 2:
			if(frame >= 120 && frame % 80 == 0) {
				double shotAngle = TargetPlayerAngle();
				EBC->SetEnemyBullet(2, &position, 3, shotAngle, 0.8);
			}
		default:
			break;
	}
}

void Enemy001::Draw() {
	int angleImgNum;
	if(angle > 70.0f) {
		angleImgNum = 14;
	} else if (angle < -70.0f) {
		angleImgNum = -14;
    } else {
		angleImgNum = round(angle/10) * 2;
	}

	if(angleImgNum <= 0) {
		DrawGraph(round(position.x - X_SIZE / 2), round(position.y - Y_SIZE / 2), image[imgNum + (-angleImgNum)], TRUE);
	} else {
		DrawTurnGraph(round(position.x - X_SIZE / 2), round(position.y - Y_SIZE / 2), image[imgNum + angleImgNum], TRUE);
	}

	if(frame % 2 == 0) {
		imgNum++;
		if(imgNum >= IMAGE_NUM) imgNum = 0;
	}
}

void Enemy001::DeathFunc() {
	for(int i = 0; i < 2; i++) {
		SC->SetScrap(1, &position);
	}
}
