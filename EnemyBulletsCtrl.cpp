#include "EnemyBulletsCtrl.h"

std::vector<EnemyBullet*> EnemyBulletsCtrl::bulletsVec;

void EnemyBulletsCtrl::Init() {
	bulletsVec.clear();
}

void EnemyBulletsCtrl::Update() {
	for(auto itr = bulletsVec.begin(); itr != bulletsVec.end(); ) {
		if((*itr)->Update()) {
			itr++;
		} else {
			itr = bulletsVec.erase(itr);
		}
	}
}

void EnemyBulletsCtrl::Draw() {
	for(auto itr : bulletsVec) {
		itr->Draw();
	}
}

void EnemyBulletsCtrl::SetEnemyBullet(int type, const Vector2 pos, double speed, double degAngle, double size) {
	if(pos.x >= 0 && pos.x <= GAME_WINDOW_XSIZE && pos.y >= 0 && pos.y <= GAME_WINDOW_YSIZE) {
		switch(type) {
			case 1:
				bulletsVec.emplace_back(new EBullet_01(pos, speed, degAngle * (M_PI/180), size));
				break;
			case 2:
				bulletsVec.emplace_back(new EBullet_02(pos, speed, degAngle * (M_PI/180), size));
				break;
			default:
				break;
		}
	}
}

void EnemyBulletsCtrl::DeleteAllBullet() {
	for(auto itr : bulletsVec) {
		itr->DeathFunc();
	}
}