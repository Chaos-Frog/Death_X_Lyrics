#pragma once
#include "StageBase.h"

class Stage_1 : public StageBase {
    private:
    public:
        Stage_1();
        void Update() override;
        void BG_Update() override;
        void BG_Draw() override;
};

