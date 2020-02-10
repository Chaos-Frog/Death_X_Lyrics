#include "EnemyBullet.h"
EnemyBullet::EnemyBullet(int type, Vector2* pos, double spd, double radA, double size, Assets* as) {
	switch(type) {
		case 1:
			image = &as->enemyBullet01;
			break;
		case 2:
			image = &as->enemyBullet02;
			break;
		default:
			break;
	}

	position = *pos;
	speed = spd;
	angle = radA;
	bulletSize = size;
}

bool EnemyBullet::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	if(position.x + 16 * bulletSize >= GAME_WINDOW_X1 && position.x - 16 * bulletSize <= GAME_WINDOW_X2 &&
	   position.y + 16 * bulletSize >= GAME_WINDOW_Y1 && position.y - 16 * bulletSize <= GAME_WINDOW_Y2) {
		DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
		return true;
	} else {
		return false;
	}
}