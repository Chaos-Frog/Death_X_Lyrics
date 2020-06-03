#include "Enemy002.h"
Enemy002::Enemy002(Vector2* pos, int mp, int dp, int* img, Player* pla, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) : Enemy(1, pos, 10, mp, dp, pla, ebc, sc) {
	image = img;
	imgNum = 0;
	first = position;
	angle = 0.0f;

	colliders.emplace_back(new Circle_C(&position, Vector2(0, 0), 25));
}

void Enemy002::Update() {
	Moving();
	Draw();
	Danmaku();

	for(auto col : colliders) {
		col->Update();
	}

	frame++;
}

void Enemy002::Moving() {
	switch(movePatern) {
		case 1:
			if(frame < 60) {
				double t = (double)frame / 60.0;
				position.y = (200.0 * t) + first.y;
			}
			break;
		case 2:
			if(frame < 60) {
				double t = (double)frame / 60.0;
				position.y = (200.0 * t) + first.y;
			} else {
				double a = TargetPlayerAngle() - 90;
				if(a > angle) {
					if(a - angle > 180.0f) {
						if(angle - a >= 5.0f) angle -= 5.0f;
						else                  angle = a;
					} else {
						if(a - angle >= 5.0f) angle += 5.0f;
						else                  angle = a;
					}
				} else if(a < angle) {
					if(angle - a > 180.0f) {
						if(a - angle >= 5.0f) angle += 5.0f;
						else                  angle = a;
					} else {
						if(angle - a >= 5.0f) angle -= 5.0f;
						else                  angle = a;
					}
				}
				if(angle > 180.0f)       angle -= 180.0f;
				else if(angle < -180.0f) angle += 180.0f;
			}
			break;
		default:
			break;
	}
}


void Enemy002::Danmaku() {
	switch(danmakuPatern) {
		case 1:
			if(frame >= 120) {
				if(frame % 120 == 20 || frame % 120 == 40 || frame % 120 == 60) {
					double a = angle * (M_PI/180.0f);
					shotPos[0] = Vector2(cos(a) * 20, sin(a) * 20);
					shotPos[1] = Vector2(cos(a) * -20, sin(a) * -20);
					EBC->SetEnemyBullet(2, position + shotPos[0], 3, angle + 90, 0.6);
					EBC->SetEnemyBullet(2, position + shotPos[1], 3, angle + 90, 0.6);
				}
			}
			break;
		default:
			break;
	}
}

void Enemy002::Draw() {
	int angleImgNum = round(angle/15) * LOOP;

	if(angleImgNum <= 0) {
		DrawGraph(round(position.x - X_SIZE / 2), round(position.y - Y_SIZE / 2), image[imgNum + (-angleImgNum)], TRUE);
	} else {
		DrawTurnGraph(round(position.x - X_SIZE / 2), round(position.y - Y_SIZE / 2), image[imgNum + angleImgNum], TRUE);
	}

	if(frame % 2 == 0) {
		imgNum++;
		if(imgNum >= LOOP) imgNum = 0;
	}
}

void Enemy002::DeathFunc() {
	for(int i = 0; i < 2; i++) {
		SC->SetScrap(1, &position);
	}
}
