#include "Enemy001.h"
Enemy001::Enemy001(Vector2* pos, int mp, int dp, int* img, EnemyBulletsCtrl* ebc) : Enemy(1, pos, 4, mp, dp, ebc) {
	image = img;
	imgNum = 0;
}

void Enemy001::Update() {
	Moving();
	Draw();
	Danmaku();

	frame++;
}

void Enemy001::Moving() {
	switch(movePatern) {
		case 1:
			// TEST
			if(frame >= 600) {
				position.x = sin((frame-600) * (2 * (M_PI / 180))) * 160 + 640;
				position.y = sin((frame-600) * (4 * (M_PI / 180))) * 80 + 250;
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
			if(frame >= 600 && frame % 2 == 0) {
				double a = (frame-600) * 5 + (frame-600) / 5;
				EBC->SetEnemyBullet(1, &position, 1.0, a * (M_PI / 180), 0.6);
				//EBC->SetEnemyBullet(1, &position, 1.1, (a + 45) * (M_PI / 180), 0.6);
				EBC->SetEnemyBullet(1, &position, 1.2, (a + 90) * (M_PI / 180), 0.6);
				//EBC->SetEnemyBullet(1, &position, 1.3, (a + 135) * (M_PI / 180), 0.6);
				EBC->SetEnemyBullet(1, &position, 1.4, (a + 180) * (M_PI / 180), 0.6);
				//EBC->SetEnemyBullet(1, &position, 1.5, (a + 225) * (M_PI / 180), 0.6);
				EBC->SetEnemyBullet(1, &position, 1.6, (a + 270) * (M_PI / 180), 0.6);
				//EBC->SetEnemyBullet(1, &position, 1.7, (a + 315) * (M_PI / 180), 0.6);
			}
			break;
		default:
			break;
	}
}

void Enemy001::Draw() {
	DrawGraph(round(position.x - X_SIZE/2), round(position.y - Y_SIZE/2), image[imgNum], TRUE);
	if(frame % 6 == 0) {
		imgNum++;
		if(imgNum >= IMAGE_NUM) imgNum = 0;
	}
}
