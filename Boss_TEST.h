#pragma once
#include "Boss.h"

struct Parts {
    int HP              = 0;
    Vector2 position    = Vector2(0, 0);
    Vector2 relativePos = Vector2(0, 0);
    Collider* col       = new Collider(&position, Vector2(0, 0));
};

class Boss_TEST : public Boss {
    private:
        int destroyParts;

    public:
        Parts bossParts[20];
        vector<Collider*> colliders;

        Boss_TEST();
        bool Update() override;
        void Draw() override;
        bool DeathFunc() override;
        void CheckCol_Boss_PBullets() override;
        void CheckCol_Boss_Player() override;
};

