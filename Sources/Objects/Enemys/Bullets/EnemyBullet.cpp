#include "EnemyBullet.h"

/* “G’eŠî’êƒNƒ‰ƒX */
EnemyBullet::EnemyBullet(ImageData* id, Collider* col, Vector2 pos, int bt, double spd, double radA, double size) {
	image = id;
	collider = col;
	position = pos;

	bulletType = bt;
	speed = spd;
	angle = radA;
	bulletSize = size;

	frame = 0;
	death = false;
}

bool EnemyBullet::Update() {
	frame++;
	if(!death) return Moving();
	else       return DeathFunc();
}
bool EnemyBullet::Moving() {
	position.x += cos(angle) * speed;
	position.y += sin(angle) * speed;

	collider->Update();

	return CheckInArea();
}
void EnemyBullet::Draw() {}
bool EnemyBullet::DeathFunc() { return false; }

bool EnemyBullet::CheckInArea() {
	return (position.x >= bulletSize && position.x <= GAME_WINDOW_XSIZE + bulletSize &&
		    position.y >= bulletSize && position.y <= GAME_WINDOW_YSIZE + bulletSize);
}


/* ’Êí’eiÔj */
EBullet_01::EBullet_01(Vector2 pos, double spd, double radA, double size)
	       :EnemyBullet(&Assets::enemyBullet01, new Circle_C(&position, Vector2(0, 0), size * 12), pos, 1, spd, radA, size) {
}

bool EBullet_01::Moving() {
	return EnemyBullet::Moving();
}

void EBullet_01::Draw() {
	if(!death) {
		DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image->handle, TRUE, FALSE);
	} else {
		DrawRotaGraph(round(position.x), round(position.y), Easing::Ease_Out_Cubic(bulletSize, 0.0, (double)frame / 10.0), angle, *image->handle, TRUE, FALSE);
	}
}

bool EBullet_01::DeathFunc() {
	if(!death) {
		death = true;
		frame = 0;
		return true;
	} else if(frame < 10) {
		return true;
	}

	return false;
}


/* ’Êí’eiÂj */
EBullet_02::EBullet_02(Vector2 pos, double spd, double radA, double size)
	       :EnemyBullet(&Assets::enemyBullet02, new Circle_C(&position, Vector2(0, 0), size * 12), pos, 2, spd, radA, size) {
}

bool EBullet_02::Moving() {
	return EnemyBullet::Moving();
}

void EBullet_02::Draw() {
	if(!death) {
		DrawRotaGraph(round(position.x), round(position.y), bulletSize, angle, *image->handle, TRUE, FALSE);
	} else {
		DrawRotaGraph(round(position.x), round(position.y), Easing::Ease_Out_Cubic(bulletSize, 0.0, (double)frame/10.0), angle, *image->handle, TRUE, FALSE);
	}
}

bool EBullet_02::DeathFunc() {
	if(!death) {
		death = true;
		frame = 0;
		return true;
	} else if(frame < 10) {
		return true;
	}
	return false;
}