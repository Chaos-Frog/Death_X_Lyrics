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
		case 0:
			break;
		default:
			break;
	}
}


void Enemy001::Danmaku() {
	switch(danmakuPatern) {
		case 0:
			EBC->SetEnemyBullet(1, &position, 4, ((frame%16*22.5)+(int)(frame / 16)*4)*(M_PI/180), 0.6);
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
