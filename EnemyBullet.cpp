#include "EnemyBullet.h"
EnemyBullet::EnemyBullet(Vector2* pos, double spd, double radA, double size, Assets* as) {
	bulletType = 0;
	position = *pos;
	speed = spd;
	angle = radA;
	bulletSize = size;
}
bool EnemyBullet::Moving() { return false; }
void EnemyBullet::Draw() {}


EBullet_01::EBullet_01(Vector2* pos, double spd, double radA, double size, Assets* as) : EnemyBullet(pos, spd, radA, size, as) {
	bulletType = 1;
	image = &as->enemyBullet01;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize*16);
}

bool EBullet_01::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return (position.x + radius >= GAME_WINDOW_X1 && position.x - radius <= GAME_WINDOW_X2 &&
			position.y + radius >= GAME_WINDOW_Y1 && position.y - radius <= GAME_WINDOW_Y2);
}

void EBullet_01::Draw() {
	DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
}


EBullet_02::EBullet_02(Vector2* pos, double spd, double radA, double size, Assets* as) : EnemyBullet(pos, spd, radA, size, as) {
	bulletType = 2;
	image = &as->enemyBullet02;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize*16);
}

bool EBullet_02::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return (position.x + radius >= GAME_WINDOW_X1 && position.x - radius <= GAME_WINDOW_X2 &&
			position.y + radius >= GAME_WINDOW_Y1 && position.y - radius <= GAME_WINDOW_Y2);
}

void EBullet_02::Draw() {
	DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
}