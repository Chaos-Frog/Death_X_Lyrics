#include "EnemyCtrl.h"
#include "GameController.h"

std::vector<Enemy_Air*>    EnemyCtrl::enemysVec_Air;
std::vector<Enemy_Ground*> EnemyCtrl::enemysVec_Ground;

Boss* EnemyCtrl::boss = nullptr;

void EnemyCtrl::Init() {
	enemysVec_Air.clear();
	enemysVec_Ground.clear();
	boss = NULL;
}

void EnemyCtrl::Update() {
	for(auto itr = enemysVec_Air.begin(); itr != enemysVec_Air.end();) {
		if((*itr)->Update()) itr++;
		else                 itr = enemysVec_Air.erase(itr);
	}

	for(auto itr = enemysVec_Ground.begin(); itr != enemysVec_Ground.end();) {
		if((*itr)->Update()) itr++;
		else                 itr = enemysVec_Ground.erase(itr);
	}

	//boss->Update();
}

void EnemyCtrl::Draw() {
	sort(enemysVec_Ground.begin(), enemysVec_Ground.end(), [](const Enemy_Ground* eg1, const Enemy_Ground* eg2) {
		return eg1->position.y < eg2->position.y;
	});
	for(auto itr : enemysVec_Ground) {
		itr->Draw();
	}
	for(auto itr : enemysVec_Air) {
		itr->Draw();
	}
	
	//boss->Draw();
}

void EnemyCtrl::SetEnemy(int type, Vector2* pos, int mp, int dp) {
	switch(type) {
		case -1:
			enemysVec_Air.emplace_back(new TestEnemy_Air(pos, mp, dp));
			break;

		case 1:
			enemysVec_Air.emplace_back(new Enemy001(pos, mp, dp));
			break;

		case 2:
			enemysVec_Air.emplace_back(new Enemy002(pos, mp, dp));
			break;

		case 101:
			enemysVec_Ground.emplace_back(new Enemy101(pos, mp, dp));
			break;

		default:
			break;
	}
}

void EnemyCtrl::SetBoss(int stageNum) {
	switch(stageNum) {
		default:
			boss = NULL;
			break;
	}
}