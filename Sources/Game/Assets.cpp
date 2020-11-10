#include "Assets.h"

const char* Assets::StagePathes[5] = {
    "Assets/StageData/Stage1.csv",
    "Assets/StageData/Stage2.csv",
    "Assets/StageData/Stage3.csv",
    "Assets/StageData/Stage4.csv",
    "Assets/StageData/Stage5.csv"
};

bool Assets::loading = true;

vector<EnemyData> Assets::Stages[5];

ImageData Assets::player01         = { new int[12], 12, Vector2(120, 100) };
ImageData Assets::player01_Hit     = { new int[12], 12, Vector2(120, 100) };
ImageData Assets::playerBullet01   = { 0, 1, Vector2(32, 32) };
ImageData Assets::playerMissile    = { 0, 1, Vector2(64, 64) };
ImageData Assets::playerMissileExp = { new int[16], 16, Vector2(100, 100) };

ImageData Assets::enemy001         = { new int[26], 26, Vector2(64, 64) };
ImageData Assets::enemy002         = { new int[26], 26, Vector2(64, 64) };

ImageData Assets::enemyBullet01    = { 0, 1, Vector2(32, 32) };
ImageData Assets::enemyBullet02    = { 0, 1, Vector2(32, 32) };

ImageData Assets::scrap_S          = { new int[6], 6, Vector2(40, 40) };

void Assets::LoadAssets() {
    LoadStage(0);
    LoadTexture();
    Sleep(1000);
    loading = false;
}

void Assets::LoadTexture() {
    // 読み込み
    LoadDivGraph("Assets/Player01.png", player01.imageNum, 4, 3, player01.imageSize.x, player01.imageSize.y, player01.handle);
    LoadDivGraph("Assets/Player01_Hit.png", player01_Hit.imageNum, 4, 3, player01_Hit.imageSize.x, player01_Hit.imageSize.y, player01_Hit.handle);
    playerBullet01.handle = new int(LoadGraph("Assets/PlayerBullet.png"));
    playerMissile.handle  = new int(LoadGraph("Assets/Missile.png"));
    LoadDivGraph("Assets/Exp01.png", playerMissileExp.imageNum, 4, 4, playerMissileExp.imageSize.x, playerMissileExp.imageSize.y, playerMissileExp.handle);

    LoadDivGraph("Assets/E_001.png", enemy001.imageNum, 4, 7, enemy001.imageSize.x, enemy001.imageSize.y, enemy001.handle);
    LoadDivGraph("Assets/E_002.png", enemy002.imageNum, 4, 7, enemy002.imageSize.x, enemy002.imageSize.y, enemy002.handle);

    enemyBullet01.handle = new int(LoadGraph("Assets/EB01.png"));
    enemyBullet02.handle = new int(LoadGraph("Assets/EB02.png"));

    LoadDivGraph("Assets/Scrap_S.png", scrap_S.imageNum, 3, 2, scrap_S.imageSize.x, scrap_S.imageSize.y, scrap_S.handle);


    // ハンドルチェック
    CheckHandle(&player01);
    CheckHandle(&player01_Hit);
    CheckHandle(&playerBullet01);
    CheckHandle(&playerMissile);
    CheckHandle(&playerMissileExp);

    CheckHandle(&enemy001);
    CheckHandle(&enemy002);

    CheckHandle(&enemyBullet01);
    CheckHandle(&enemyBullet02);

    CheckHandle(&scrap_S);
}

void Assets::CheckHandle(ImageData* id) {
    for(int i = 0; i < id->imageNum; i++) {
        while(1) {
            int result = CheckHandleASyncLoad(id->handle[i]);
            if(result == TRUE)    break;
            else if(result == -1) throw "Handle Check Error...";
        }
    }
}

void Assets::LoadStage(int num) {
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

bool Assets::DrawLoading() {
    static int frame = 0;
    SetFontSize(40);
    if(frame % 60 < 20)      DrawString(20, 60, "Loading.", GetColor(0, 200, 0));
    else if(frame % 60 < 40) DrawString(20, 60, "Loading..", GetColor(0, 200, 0));
    else                     DrawString(20, 60, "Loading...", GetColor(0, 200, 0));
    frame++;
    return loading;
}