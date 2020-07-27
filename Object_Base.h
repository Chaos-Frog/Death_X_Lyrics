#pragma once
#include "DxLib.h"
#include "Define.h"
#include "Vector2.h"

class Object_Base {
    private:
    protected:
        int frame;

    public:
        Vector2 positon;

        Object_Base();
        ~Object_Base();
        virtual void Update();
};

