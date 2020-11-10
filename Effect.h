#pragma once
#include "DxLib.h"
#include "Define.h"
#include "Assets.h"
#include "Vector2.h"

class Effect {
    protected:
        ImageData* image;
        int imageCount;

        int frame;
        int step;
        bool loop;

        bool CheckInArea();

    public:
        bool destroy;
        Vector2 position;
        Vector2 scale;

        Effect(ImageData* id, int stp, bool lp, Vector2 pos, Vector2 scl);
        ~Effect();
        virtual bool Update();
        void Draw();
};

