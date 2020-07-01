#include "EnemyBullet.h"

/* “G’eŠî’êƒNƒ‰ƒX */
EnemyBullet::EnemyBullet(const Vector2 pos, double spd, double radA, double size, Assets* as) {
	bulletType = 0;
	frame = 0;
	position = pos;
	speed = spd;
	angle = radA;
	bulletSize = size;
	death = false;
}

bool EnemyBullet::Update() {
	frame++;
	if(!death) return Moving();
	else       return DeathFunc();
}
bool EnemyBullet::Moving() { return false; }
void EnemyBullet::Draw() {}
bool EnemyBullet::DeathFunc() { return false; }


/* ’Êí’eiÔj */
EBullet_01::EBullet_01(const Vector2 pos, double spd, double radA, double size, Assets* as) : EnemyBullet(pos, spd, radA, size, as) {
	bulletType = 1;
	image = &as->enemyBullet01;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize);
}

bool EBullet_01::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return (position.x + bulletSize >= 0 && position.x - bulletSize <= GAME_WINDOW_XSIZE &&
			position.y + bulletSize >= 0 && position.y - bulletSize <= GAME_WINDOW_YSIZE);
}

void EBullet_01::Draw() {
	if(!death) {
		DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
	} else {
		DrawRotaGraph(round(position.x), round(position.y), 1.0 - ((double)frame/20.0), angle, *image, TRUE, FALSE);
	}
}

bool EBullet_01::DeathFunc() {
	if(!death) {
		death = true;
		frame = 0;
		return true;
	} else {
		if(frame < 20) return true;
		else           return false;
	}
}


/* ’Êí’eiÂj */
EBullet_02::EBullet_02(const Vector2 pos, double spd, double radA, double size, Assets* as) : EnemyBullet(pos, spd, radA, size, as) {
	bulletType = 2;
	image = &as->enemyBullet02;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize*16);
}

bool EBullet_02::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return (position.x + bulletSize*16 >= 0 && position.x - bulletSize*16 <= GAME_WINDOW_XSIZE &&
			position.y + bulletSize*16 >= 0 && position.y - bulletSize*16 <= GAME_WINDOW_YSIZE);
}

void EBullet_02::Draw() {
	if(!death) {
		DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image, TRUE, FALSE);
	} else {
		DrawRotaGraph(round(position.x), round(position.y), 1.0 - ((double)frame/20.0), angle, *image, TRUE, FALSE);
	}
}

bool EBullet_02::DeathFunc() {
	if(!death) {
		death = true;
		frame = 0;
		return true;
	} else {
		if(frame < 20) return true;
		else           return false;
	}
}