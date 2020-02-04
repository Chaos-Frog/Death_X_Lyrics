#include "Enemy001.h"
Enemy001::Enemy001(Vector2* pos, int mp, int dp) : Enemy(pos, mp, dp) {
    HP = 4;
	enemyType = 1;
}

void Enemy001::Update() {
	Moving();
	Danmaku();
}

void Enemy001::Moving() {
	switch(enemyType) {
		case 0:
			break;
		default:
			break;
	}
}


void Enemy001::Danmaku() {
	switch(enemyType) {
		case 0:
			break;
		default:
			break;
	}
}
