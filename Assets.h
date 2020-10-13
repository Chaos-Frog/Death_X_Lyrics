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

class Assets {
    private:
        static const char* StagePathes[5];
        static bool loading;

        static void LoadTexture();
        static void CheckHandle(int* handle);
        static void LoadStage(int num);

    public:
        static vector<EnemyData> Stages[5];
        
        static int player01[12];
        static int player01_Hit[12];
        static int playerBullet01;
        static int playerMissile;
        static int playerMissileExp[16];

        static int enemy001[26];
        static int enemy002[26];

        static int enemyBullet01;
        static int enemyBullet02;

        static int scrap_S[6];

        static void LoadAssets();
        static bool DrawLoading();
};