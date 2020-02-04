#include "EnemyCtrl.h"
void EnemyCtrl::Update() {
	for(int i=0; i<enemysVec.size(); i++) {
		enemysVec[i]->Update();
	}
}

void EnemyCtrl::SetEnemy(int type, Vector2* pos) {
	switch(type) {
		case 1:
			enemysVec.emplace_back(new Enemy001(pos, 0, 0));
			break;
		default:
			break;
	}
}