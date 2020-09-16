#include "Assets.h"

Assets::Assets() {
    StageLoad(0);

    LoadDivGraph("Assets/Player01.png", 12, 4, 3, 120, 100, player01);
    LoadDivGraph("Assets/Player01_Hit.png", 12, 4, 3, 120, 100, player01_Hit);
    playerBullet01 = LoadGraph("Assets/PlayerBullet.png");
    playerMissile = LoadGraph("Assets/Missile.png");
    LoadDivGraph("Assets/Exp01.png", 16, 4, 4, 100, 100, playerMissileExp);

    LoadDivGraph("Assets/E_001.png", 26, 4, 7, 64, 64, enemy001);
    LoadDivGraph("Assets/E_002.png", 26, 4, 7, 64, 64, enemy002);

    enemyBullet01 = LoadGraph("Assets/EB01.png");
    enemyBullet02 = LoadGraph("Assets/EB02.png");

    LoadDivGraph("Assets/Scrap_S.png", 6, 3, 2, 40, 40, scrap_S);
}
Assets::~Assets() {}

void Assets::StageLoad(int num) {
    ifstream ifs(StagePathes[num]);
    if(ifs.fail()) {
        throw "StageData Loading Error...";
        return;
    }

    string line;
    getline(ifs, line);
    while(getline(ifs, line)) {
        istringstream stream(line);
        vector<string> elemVec;
        EnemyData ed;
        string elem;

        while(getline(stream, elem, ',')) elemVec.push_back(elem);
        ed.frame         = atoi(elemVec[0].c_str());
        ed.enemyType     = atoi(elemVec[1].c_str());
        int pos_x        = atoi(elemVec[2].c_str());
        int pos_y        = atoi(elemVec[3].c_str());
        ed.setPos        = Vector2(pos_x, pos_y);
        ed.danmakuPatern = atoi(elemVec[4].c_str());
        ed.movePatern    = atoi(elemVec[5].c_str());

        Stages[num].push_back(ed);
    }
}