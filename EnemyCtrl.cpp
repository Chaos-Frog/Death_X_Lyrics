#include "EnemyCtrl.h"
#include "GameController.h"

EnemyCtrl::EnemyCtrl(Assets* img, GameController* gc) {
	images = img;
	gameCtrl = gc;
}

EnemyCtrl::~EnemyCtrl() {
	enemysVec_Air.clear();
}

void EnemyCtrl::Update() {
	for(auto itr = enemysVec_Air.begin(); itr != enemysVec_Air.end();) {
		if((*itr)->Update()) {
			itr = enemysVec_Air.erase(itr);
		} else {
			itr++;
		}
	}

	for(auto itr = enemysVec_Ground.begin(); itr != enemysVec_Ground.end();) {
		if((*itr)->Update()) {
			itr = enemysVec_Ground.erase(itr);
		} else {
			itr++;
		}
	}
}

void EnemyCtrl::Draw() {
	for(auto itr : enemysVec_Ground) {
		itr->Draw();
	}
	for(auto itr : enemysVec_Air) {
		itr->Draw();
	}
}

void EnemyCtrl::SetEnemy(int type, Vector2* pos, int mp, int dp) {
	switch(type) {
		case 1:
			enemysVec_Air.emplace_back(new Enemy001(pos, mp, dp, images->enemy001, gameCtrl));
			break;
		case 2:
			enemysVec_Air.emplace_back(new Enemy002(pos, mp, dp, images->enemy002, gameCtrl));
			break;
		default:
			break;
	}
}