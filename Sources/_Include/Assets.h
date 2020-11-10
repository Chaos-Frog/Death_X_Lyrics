#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>

using namespace std;

struct EnemyData {
    int frame;
    int enemyType;
    Vector2 setPos;
    int danmakuPatern;
    int movePatern;
};

struct ImageData {
    int* handle;
    int imageNum;
    Vector2 imageSize;
};

class Assets {
    private:
        static const char* StagePathes[5];
        static bool loading;

        static void LoadTexture();
        static void CheckHandle(ImageData* id);
        static void LoadStage(int num);

    public:
        static vector<EnemyData> Stages[5];
        
        static ImageData player01;
        static ImageData player01_Hit;
        static ImageData playerBullet01;
        static ImageData playerMissile;
        static ImageData playerMissileExp;

        static ImageData enemy001;
        static ImageData enemy002;

        static ImageData enemyBullet01;
        static ImageData enemyBullet02;

        static ImageData scrap_S;

        static void LoadAssets();
        static bool DrawLoading();
};