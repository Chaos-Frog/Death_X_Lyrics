#include "EnemyCtrl.h"
#include "GameController.h"

EnemyCtrl::EnemyCtrl(GameController* gc) {
	gameCtrl = gc;
	boss = new Boss_TEST(gameCtrl);
}

EnemyCtrl::~EnemyCtrl() {
	enemysVec_Air.clear();
	enemysVec_Ground.clear();
	delete boss;
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
		case 1:
			enemysVec_Air.emplace_back(new Enemy001(pos, mp, dp, gameCtrl));
			break;
		case 2:
			enemysVec_Air.emplace_back(new Enemy002(pos, mp, dp, gameCtrl));
			break;
		case 101:
			enemysVec_Ground.emplace_back(new Enemy101(pos, mp, dp, gameCtrl));
			break;
		default:
			break;
	}
}