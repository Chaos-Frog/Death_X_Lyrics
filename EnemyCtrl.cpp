#include "EnemyCtrl.h"
EnemyCtrl::EnemyCtrl(Assets* img, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) {
	images = img;
	EBC = ebc;
	SC = sc;
}

EnemyCtrl::~EnemyCtrl() {
	enemysVec.clear();
}

void EnemyCtrl::Update() {
	for(auto &itr : enemysVec) {
		(*itr).Update();
	}
}

void EnemyCtrl::SetEnemy(int type, Vector2* pos, int mp, int dp) {
	switch(type) {
		case 1:
			enemysVec.emplace_back(std::make_shared<Enemy001>(pos, mp, dp, images->enemy001, EBC, SC));
			break;
		default:
			break;
	}
}