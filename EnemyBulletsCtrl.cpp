#include "EnemyBulletsCtrl.h"
EnemyBulletsCtrl::EnemyBulletsCtrl(Assets* as) {
	assets = as;
}

EnemyBulletsCtrl::~EnemyBulletsCtrl() {
	for(int i = 0; i < bulletsVec.size(); i++) {
		delete bulletsVec[i];
		bulletsVec.erase(bulletsVec.begin() + i);
	}
}

void EnemyBulletsCtrl::Update() {
	for(int i = 0; i < bulletsVec.size(); i++) {
		if(!bulletsVec[i]->Moving()) {
			delete bulletsVec[i];
			bulletsVec.erase(bulletsVec.begin() + i);
		}
	}
}

void EnemyBulletsCtrl::SetEnemyBullet(int type, Vector2* pos, double speed, double radAngle, double size) {
	if(pos->x >= GAME_WINDOW_X1 && pos->x <= GAME_WINDOW_X2 && pos->y >= GAME_WINDOW_Y1 && pos->y <= GAME_WINDOW_Y2) {
		bulletsVec.emplace_back(new EnemyBullet(type, pos, speed, radAngle, size, assets));
	}
}