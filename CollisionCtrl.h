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

        static void Check_PBullet_Enemy_Collision();  // PlayerBullet��Enemy
        static void Check_PBullet_Scraps_Collision(); // PlayerBullet��Scraps
        static bool Check_Player_Enemy_Collision();   // Player��Enemy
        static bool Check_Player_EBullet_Collision(); // Player��EnemyBullet
        static void Check_Player_Scraps_Collision();  // Player��Scraps

        static void Debug(ColliderParam* param);

    public:
        static void Update();
        static void DebugDraw();
};

