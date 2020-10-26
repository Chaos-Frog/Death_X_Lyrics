#include "Enemy001.h"
#include "GameController.h"

#define E1_LOOP 2

Enemy001::Enemy001(Vector2* pos, int mp, int dp, GameController* gc)
	     :Enemy_Air(1, pos, 5, 100, mp, dp, gc) {
	image = Assets::enemy001.handle;
	imgNum = 0;
	first = *pos;
	angle = 0.0f;
	enableArea = {
		Vector2(-Assets::enemy001.imageSize.x, -Assets::enemy001.imageSize.y),
		Vector2(GAME_WINDOW_XSIZE + Assets::enemy001.imageSize.x, GAME_WINDOW_YSIZE + Assets::enemy001.imageSize.y)
	};

	colliders.emplace_back(new Circle_C(&position, Vector2(0, 0), 25));
}

void Enemy001::MovingAir() {
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


void Enemy001::Danmaku() {
	switch(danmakuPatern) {
		case 1:
			if(frame >= 120 && frame % 120 == 0) {
				SetEnemyBullet(1, position, 2, 90, 0.6);
			}
			break;
		case 2:
			if(frame >= 120 && frame % 80 == 0) {
				double shotAngle = TargetPlayerAngle();
				SetEnemyBullet(2, position, 3, shotAngle, 0.8);
			}
		default:
			break;
	}
}

void Enemy001::Draw() {
	int angleImgNum = round(angle/15) * E1_LOOP;

	if(angleImgNum <= 0) {
		DrawGraph(round(position.x - Assets::enemy001.imageSize.x / 2), round(position.y - Assets::enemy001.imageSize.y / 2), image[imgNum + (-angleImgNum)], TRUE);
	} else {
		DrawTurnGraph(round(position.x - Assets::enemy001.imageSize.x / 2), round(position.y - Assets::enemy001.imageSize.y / 2), image[imgNum + angleImgNum], TRUE);
	}

	if(frame % 2 == 0) {
		imgNum++;
		if(imgNum >= E1_LOOP) imgNum = 0;
	}
}

bool Enemy001::DeathFunc() {
	SetScrap(1, 2, position);
	gameCtrl->effCtrl->SetEffects(0, position, Vector2(1.5, 1.5), 1, false);
	return false;
}
