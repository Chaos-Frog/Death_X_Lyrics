#include "TestEnemy_Air.h"
#include "GameController.h"
#include "EnemyBulletsCtrl.h"
#include "ScrapsCtrl.h"
#include "EffectsCtrl.h"

TestEnemy_Air::TestEnemy_Air(Vector2* pos, int mp, int dp)
			  :Enemy_Air(Enemys::TEST, pos, mp, dp) {
	first = *pos;
	angle = 0.0f;
	enableArea = {
		Vector2(-60.0, -60.0),
		Vector2((double)GAME_WINDOW_XSIZE + 60, (double)GAME_WINDOW_YSIZE + 60)
	};

	colliders.emplace_back(new Circle_C(&position, Vector2(0, 0), 25));
}

void TestEnemy_Air::MovingAir() {
	switch(movePatern) {
		case 1:
			TestEnemy_Air::Moving001();
			break;
	}
}


void TestEnemy_Air::Danmaku() {
	switch(danmakuPatern) {
		case 1:
			if(frame >= 60) {
				if(frame % 40 == 0) {
					double sa = TargetPlayerAngle();
					EnemyBulletsCtrl::SetEnemyBullet(1, position, 4.0, sa, 1.2);
				}
			}
			break;
	}
}

void TestEnemy_Air::Draw() {
	DrawCircle(position.x, position.y, 30, GetColor(0, 100, 0), TRUE);
}

bool TestEnemy_Air::DeathFunc() {
	ScrapsCtrl::SetScrap(1, position, 2);
	EffectsCtrl::SetEffects(0, position, Vector2(1.5, 1.5), 1);
	return false;
}


/* à⁄ìÆÉpÉ^Å[Éì */
void TestEnemy_Air::Moving001() {
	double vel = 0.0;
	if(frame <= 90) {
		double t = (double)frame / 90.0;
		vel = Easing::Ease_Out_Quad(10.0, 0.0, t);
	} else if(frame <= 210) {
		vel = 0.0;
		if(frame == 210) withdrawal = true;
	} else {
		double t = ((double)frame - 210.0) / 90.0;
		vel = Easing::Ease_In_Quad(0.0, -10.0, t);
	}

	position.y += vel;
}

void TestEnemy_Air::Moving002() {

}

void TestEnemy_Air::Moving003() {

}