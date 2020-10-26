#pragma once
#include "DxLib.h"
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"

class Effect {
    protected:
        int* images;
        int imageNum;
        int imageCount;
        int frame;
        int step;
        bool loop;
        Vector2 size;

        bool CheckInArea();

    public:
        bool destroy;
        Vector2 position;
        Vector2 scale;

        Effect(int* img, int stp, bool lp, Vector2 pos, Vector2 sz, Vector2 scl);
        ~Effect();
        virtual bool Update();
        void Draw();
};

