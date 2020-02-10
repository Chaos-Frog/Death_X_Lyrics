#include "EnemyCtrl.h"
EnemyCtrl::EnemyCtrl(Assets* img, EnemyBulletsCtrl* ebc) {
	images = img;
	EBC = ebc;
}

EnemyCtrl::~EnemyCtrl() {
	for(int i = 0; i < enemysVec.size(); i++) {
		delete enemysVec[i];
		enemysVec.erase(enemysVec.begin() + i);
	}
}

void EnemyCtrl::Update() {
	for(int i=0; i<enemysVec.size(); i++) {
		enemysVec[i]->Update();
	}
}

void EnemyCtrl::SetEnemy(int type, Vector2* pos, int mp, int dp) {
	switch(type) {
		case 1:
			enemysVec.emplace_back(new Enemy001(pos, mp, dp, images->enemy001, EBC));
			break;
		default:
			break;
	}
}