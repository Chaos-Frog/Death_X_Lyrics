#include "EnemyCtrl.h"
#include "GameController.h"

EnemyCtrl::EnemyCtrl(Assets* img, GameController* gc) {
	images = img;
	gameCtrl = gc;
}

EnemyCtrl::~EnemyCtrl() {
	enemysVec.clear();
}

void EnemyCtrl::Update() {
	for(auto itr = enemysVec.begin(); itr != enemysVec.end();) {
		if((*itr)->Update()) {
			itr = enemysVec.erase(itr);
		} else {
			itr++;
		}
	}
}

void EnemyCtrl::Draw() {
	for(auto itr : enemysVec) {
		itr->Draw();
	}
}

void EnemyCtrl::SetEnemy(int type, Vector2* pos, int mp, int dp) {
	switch(type) {
		case 1:
			enemysVec.emplace_back(new Enemy001(pos, mp, dp, images->enemy001, gameCtrl));
			break;
		case 2:
			enemysVec.emplace_back(new Enemy002(pos, mp, dp, images->enemy002, gameCtrl));
			break;
		default:
			break;
	}
}