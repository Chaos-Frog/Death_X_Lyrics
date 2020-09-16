#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
        const char* StagePathes[5] = {
            "Assets/StageData/Stage1.csv",
            "Assets/StageData/Stage2.csv",
            "Assets/StageData/Stage3.csv",
            "Assets/StageData/Stage4.csv",
            "Assets/StageData/Stage5.csv"
        };

        void StageLoad(int num);

    public:
        vector<EnemyData> Stages[5];
        
        int player01[12];
        int player01_Hit[12];
        int playerBullet01;
        int playerMissile;
        int playerMissileExp[16];

        int enemy001[26];
        int enemy002[26];

        int enemyBullet01;
        int enemyBullet02;

        int scrap_S[6];

        Assets();
        ~Assets();
};