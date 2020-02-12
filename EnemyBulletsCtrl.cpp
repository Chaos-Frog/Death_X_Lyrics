#include "EnemyBulletsCtrl.h"
EnemyBulletsCtrl::EnemyBulletsCtrl(Assets* as) {
	assets = as;
}

EnemyBulletsCtrl::~EnemyBulletsCtrl() {
	DeleteAllBullet();
}

void EnemyBulletsCtrl::Update() {
	auto itr = bulletsVec.begin();
	while(itr != bulletsVec.end()) {
		if(itr->Moving()) {
			itr->Draw();
			itr++;
		} else {
			itr = bulletsVec.erase(itr);
		}
	}
}

void EnemyBulletsCtrl::SetEnemyBullet(int type, Vector2* pos, double speed, double radAngle, double size) {
	if(pos->x >= GAME_WINDOW_X1 && pos->x <= GAME_WINDOW_X2 && pos->y >= GAME_WINDOW_Y1 && pos->y <= GAME_WINDOW_Y2) {
		bulletsVec.emplace_back(EnemyBullet(type, pos, speed, radAngle, size, assets));
	}
}

void EnemyBulletsCtrl::DeleteAllBullet() {
	bulletsVec.clear();
}