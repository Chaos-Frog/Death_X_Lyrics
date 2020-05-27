#include "EnemyBulletsCtrl.h"
EnemyBulletsCtrl::EnemyBulletsCtrl(Assets* as) {
	assets = as;
}

EnemyBulletsCtrl::~EnemyBulletsCtrl() {
	DeleteAllBullet();
}

void EnemyBulletsCtrl::Update() {
	for(auto itr = bulletsVec.begin(); itr != bulletsVec.end(); ) {
		if((*itr)->Moving()) {
			(*itr)->Draw();
			itr++;
		} else {
			itr = bulletsVec.erase(itr);
		}
	}
}

void EnemyBulletsCtrl::SetEnemyBullet(int type, Vector2* pos, double speed, double degAngle, double size) {
	if(pos->x >= GAME_WINDOW_X1 && pos->x <= GAME_WINDOW_X2 && pos->y >= GAME_WINDOW_Y1 && pos->y <= GAME_WINDOW_Y2) {
		switch(type) {
			case 1:
				bulletsVec.emplace_back(new EBullet_01(pos, speed, degAngle * (M_PI/180), size, assets));
				break;
			case 2:
				bulletsVec.emplace_back(new EBullet_02(pos, speed, degAngle * (M_PI/180), size, assets));
				break;
			default:
				break;
		}
	}
}

void EnemyBulletsCtrl::DeleteAllBullet() {
	bulletsVec.clear();
}