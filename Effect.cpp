#include "Effect.h"

Effect::Effect(int* img, int stp, bool lp, Vector2 pos, Vector2 sz, Vector2 scl) {
    images = img;
    imageNum = 0;
    imageCount = 0;
    frame = 0;
    step = stp;
    loop = lp;
    destroy = false;

    position = pos;
    size = sz;
    scale = scl;
}
Effect::~Effect(){}

bool Effect::Update() {
    if(destroy) return false;

    if(frame % step == 0) imageCount = frame / step;
    if(imageCount == imageNum) {
        if(loop) {
            imageCount = 0;
            frame = 0;
        } else {
            return false;
        }
    }

    frame++;
    return true;
}

void Effect::Draw() {
    if(CheckInArea()) {
        DrawExtendGraph(round(position.x - ((size.x * scale.x) / 2)),
                        round(position.y - ((size.y * scale.y) / 2)),
                        round(position.x + ((size.x * scale.x) / 2)),
                        round(position.y + ((size.y * scale.y) / 2)),
                        images[imageCount], TRUE);
    }
}

bool Effect::CheckInArea() {
    return position.x >= -(size.x * scale.x) / 2 && position.x <= (size.x * scale.x) / 2 + GAME_WINDOW_XSIZE &&
           position.y >= -(size.y * scale.y) / 2 && position.y <= (size.y * scale.y) / 2 + GAME_WINDOW_YSIZE;
}