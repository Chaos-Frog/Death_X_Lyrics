#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include "Define.h"
#include "Vector2.h"
#include "Collider.h"

class CollisionCtrl {
    private:
        CollisionCtrl();

        static void Check_PBullet_Enemy_Collision();  // PlayerBullet‚ÆEnemy
        static void Check_PBullet_Scraps_Collision(); // PlayerBullet‚ÆScraps
        static bool Check_Player_Enemy_Collision();   // Player‚ÆEnemy
        static bool Check_Player_EBullet_Collision(); // Player‚ÆEnemyBullet
        static void Check_Player_Scraps_Collision();  // Player‚ÆScraps

        static void Debug(ColliderParam* param);

    public:
        static void Update();
        static void DebugDraw();
};

