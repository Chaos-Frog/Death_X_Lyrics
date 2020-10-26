#include "EnemyBullet.h"

/* “G’eŠî’êƒNƒ‰ƒX */
EnemyBullet::EnemyBullet(const Vector2 pos, double spd, double radA, double size) {
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

bool EnemyBullet::CheckInArea() {
	return (position.x >= bulletSize && position.x <= GAME_WINDOW_XSIZE + bulletSize &&
		    position.y >= bulletSize && position.y <= GAME_WINDOW_YSIZE + bulletSize);
}


/* ’Êí’eiÔj */
EBullet_01::EBullet_01(const Vector2 pos, double spd, double radA, double size)
	       :EnemyBullet(pos, spd, radA, size) {
	bulletType = 1;
	image = Assets::enemyBullet01.handle;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize);
}

bool EBullet_01::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return CheckInArea();
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
EBullet_02::EBullet_02(const Vector2 pos, double spd, double radA, double size)
	       :EnemyBullet(pos, spd, radA, size) {
	bulletType = 2;
	image = Assets::enemyBullet02.handle;
	collider = new Circle_C(&position, Vector2(0, 0), bulletSize);
}

bool EBullet_02::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return CheckInArea();
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