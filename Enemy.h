#pragma once
#include "DxLib.h"
#include "Vector2.h"

class Enemy {
    private:
    protected:
        Vector2 position;
        int movePatern;
        int danmakuPatern;
    public:
        int enemyType;

        Enemy(Vector2* pos, int mp, int dp);
        virtual void Update();
};

