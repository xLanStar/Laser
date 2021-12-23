#pragma once

#include <unordered_map>
#include <cmath>

#include "Game/Color.h"
#include "Game/GameObject/Pattern/Pattern.h"
#include "Game/Particle/ParticleSystemProp.h"

struct Data
{
    int highestScore[3];    //最高分
    std::string colorTheme; //顏色主題
    std::string cursorName; //
};

enum Difficulty //難度設定
{
    EASY,
    NORMAL,
    HARD
};

static std::string dataFileName = "data.bin";
static std::string colorFileName = "color.cfg";

class Setting
{
private:
    // Stored Theme Config
    std::unordered_map<std::string, Color> colorTable; // Color 字串對應 Color 物件

    // Pattern Table
    std::unordered_map<std::string, GameObject::Pattern *> patternTable; // Pattern 字串對應 Pattern 物件

    // Color
    Color color;

    // Color State
    int colorStateBorder = 50;

    // Tile
    int tileGap = 25;     //色票容器之間的距離
    int tileWidth = 250;  //色票容器的寬度
    int tileHeight = 120; //色票容器的高度
    sf::Vector2f tileRect = sf::Vector2f(getTileWidth(), getTileHeight());

    // Pantone
    int pantonePoints = 30, pantoneRadius = 32; //色票半徑
    float pantoneHoverScale = 1.2f;             //放大係數

    // Cursor
    int cursorSize = 42; //鼠標半徑
    GameObject::Pattern *cursor;

    // Text
    int titleCharacterSize = 84;                                 // Title
    int subTitleCharacterSize = 64;                              // SubTitle
    int buttonCharacterSize = 48, buttonHoverCharacterSize = 64; // Button Text
    sf::Font font;

    // Difficulty
    Difficulty difficulty; //難度設定

    // Game
    int laserBorderSize = 100; // Border 的寬度
    sf::FloatRect laserBorderRect;

    // Score
    int highestScore[3] = {0, 0, 0}; //最高分
    int currentScore = 0;            //現在的分數

    // Laser
    // - Moving Laser
    float movingLaserVelocity; //雷射移動速度
    // - Normal Laser
    int normalLaserLength = 300;   //雷射長度
    int normalLaserThickness = 10; //雷射線寬
    // - Pulse Laser
    float pulseLaserDelay = 0.5f;     //雷射延遲
    float pulseLaserPowerTime = 0.5f; //變寬所需的時間
    float pulseLaserDuration = 0.5f;  //脈衝雷射持續時間
    int pulseLaserThickness = 25;     //脈衝雷射線寬

    // Dash Line
    int dashLineLength = 75;
    int dashLineThickness = 10;

    // Laser Generator
    float generateIntervals[3] = {0.7f, 0.5f, 0.3f};

    // Particle System
    ParticleSystemProp normalLaserProp;

    // Window Size
    sf::Vector2u windowSize; //視窗長寬

public:
    // Constructor & Deconstructor
    Setting();
    ~Setting();

    // Accessors
    // Color
    std::unordered_map<std::string, Color> &getColorTable(); //取得顏色主題
    void setColorTheme(std::string colorTheme);              //設定顏色主題
    Color &findColor(std::string colorTheme);
    Color &getColor();

    // Color State
    int &getColorStateBorder();

    // Tile
    int &getTileGap();
    int &getTileWidth();
    int &getTileHeight();
    sf::Vector2f &getTileRect();

    // Pantone
    int &getPantonePoints();
    int &getPantoneRadius();
    float &getPantoneHoverScale();

    // Pattern
    std::unordered_map<std::string, GameObject::Pattern *> &getPatternTable();
    GameObject::Pattern *findCursor(std::string name);
    GameObject::Pattern *getCursor();
    int &getCursorSize();
    void setCursor(std::string name);

    // Text
    sf::Font &getFont();
    int &getTitleCharacterSize();
    int &getSubTitleCharacterSize();
    int &getButtonCharacterSize();
    int &getButtonHoverCharacterSize();

    // Difficulty
    Difficulty &getDifficulty();
    void setDifficulty(Difficulty difficulty);

    // Score
    int &getHighestScore(Difficulty difficulty);
    void setHighestScore(Difficulty difficulty, int score);
    int &getCurrentScore();
    int &getCurrentHighestScore();
    void resetCurrentScore();
    void increaseCurrentScore();
    void saveCurrentScore();

    // Game
    int &getLaserBorderSize();

    // Laser
    // Moving Laser
    float &getMovingLaserVelocity();
    // Normal Laser
    int &getNormalLaserLength();
    int &getNormalLaserThickness();
    // Pulse Laser
    float &getPulseLaserDelay();
    float &getPulseLaserPowerTime();
    float &getPulseLaserDuration();
    int &getPulseLaserThickness();

    // Dash Line
    int &getDashLineLength();
    int &getDashLineThickness();

    // Laser Generator
    float &getGenerateInterval(Difficulty difficulty);
    float &getCurrentGenerateInterval();

    // Particle System
    ParticleSystemProp &getNormalLaserProp();

    // Window
    sf::Vector2u &getWindowSize();
    sf::FloatRect &getLaserBorderRect();
    sf::Vector2f getPointAtWindow(float x, float y);

    void setWindowSize(sf::Vector2u windowSize); //設定視窗寬高

    // Save & Load
    bool load();
    void save();

    // DEBUG
    void debugParticleSystem1();
};