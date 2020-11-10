#include "Effect.h"

Effect::Effect(ImageData* id, int stp, bool lp, Vector2 pos, Vector2 scl) {
    image = id;
    imageCount = 0;
    frame = 0;
    step = stp;
    loop = lp;
    destroy = false;

    position = pos;
    scale = scl;
}
Effect::~Effect(){}

bool Effect::Update() {
    if(destroy) return false;

    if(frame % step == 0) imageCount = frame / step;
    if(imageCount == image->imageNum) {
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
        DrawExtendGraph(round(position.x - ((image->imageSize.x * scale.x) / 2)),
                        round(position.y - ((image->imageSize.y * scale.y) / 2)),
                        round(position.x + ((image->imageSize.x * scale.x) / 2)),
                        round(position.y + ((image->imageSize.y * scale.y) / 2)),
                        image->handle[imageCount], TRUE);
    }
}

bool Effect::CheckInArea() {
    return position.x >= -(image->imageSize.x * scale.x) / 2 && position.x <= (image->imageSize.x * scale.x) / 2 + GAME_WINDOW_XSIZE &&
           position.y >= -(image->imageSize.y * scale.y) / 2 && position.y <= (image->imageSize.y * scale.y) / 2 + GAME_WINDOW_YSIZE;
}