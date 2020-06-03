#include "EnemyCtrl.h"
EnemyCtrl::EnemyCtrl(Assets* img, Player* pl, EnemyBulletsCtrl* ebc, ScrapsCtrl* sc) {
	images = img;
	player = pl;
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
			enemysVec.emplace_back(new Enemy001(pos, mp, dp, images->enemy001, player, EBC, SC));
			break;
		case 2:
			enemysVec.emplace_back(new Enemy002(pos, mp, dp, images->enemy002, player, EBC, SC));
			break;
		default:
			break;
	}
}