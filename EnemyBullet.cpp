#include "EnemyBullet.h"
EnemyBullet::EnemyBullet(const Vector2 pos, double spd, double radA, double size, Assets* as) {
	bulletType = 0;
	position = pos;
	speed = spd;
	angle = radA;
	bulletSize = size;
}
bool EnemyBullet::Moving() { return false; }
void EnemyBullet::Draw() {}


EBullet_01::EBullet_01(const Vector2 pos, double spd, double radA, double size, Assets* as) : EnemyBullet(pos, spd, radA, size, as) {
	bulletType = 1;
	image = &as->enemyBullet01;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize*16);
}

bool EBullet_01::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return (position.x + radius >= 0 && position.x - radius <= GAME_WINDOW_XSIZE &&
			position.y + radius >= 0 && position.y - radius <= GAME_WINDOW_YSIZE);
}

void EBullet_01::Draw() {
	DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
}


EBullet_02::EBullet_02(const Vector2 pos, double spd, double radA, double size, Assets* as) : EnemyBullet(pos, spd, radA, size, as) {
	bulletType = 2;
	image = &as->enemyBullet02;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize*16);
}

bool EBullet_02::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return (position.x + radius >= 0 && position.x - radius <= GAME_WINDOW_XSIZE &&
			position.y + radius >= 0 && position.y - radius <= GAME_WINDOW_YSIZE);
}

void EBullet_02::Draw() {
	DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
}