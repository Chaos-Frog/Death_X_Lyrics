#pragma once
#include <cmath>
#include "DxLib.h"
#include "Vector2.h"

#define SIZE_X 100
#define SIZE_Y 100

class Player {
    private:
        Vector2* position;
        int playerImgs[12];
        int frame;
        int imgNum;
        int rotate;

        void Moving();
        void Shot();
    public:
        Player();
        void Update();
};

