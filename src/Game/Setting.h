#pragma once

#include <unordered_map>

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
    std::unordered_map<std::string, Color> colorTable; // 字串和 Color 物件的 Map

    // Pattern Table
    std::unordered_map<std::string, GameObject::Pattern *> patternTable; // 字串和 Pattern 物件的 Map

    // Color
    Color color;

    // Text
    int titleCharacterSize = 84;                                 // 標題字大小
    int subTitleCharacterSize = 64;                              // 副標題字大小
    sf::Font font;                                               //字形

    // Difficulty
    Difficulty difficulty; //難度設定

    // Score
    int highestScore[3] = {0, 0, 0}; //最高分
    int currentScore = 0;            //現在的分數

    // Moving Laser
    float movingLaserVelocity; //雷射移動速度

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

    // Pattern
    std::unordered_map<std::string, GameObject::Pattern *> &getPatternTable();
    GameObject::Pattern *findCursor(std::string name);

    // Text
    sf::Font &getFont();
    int getTitleCharacterSize();
    int getSubTitleCharacterSize();

    // Difficulty
    Difficulty &getDifficulty();
    void setDifficulty(Difficulty difficulty);

    // Score
    int getHighestScore(Difficulty difficulty);
    void setHighestScore(Difficulty difficulty, int score);
    int getCurrentScore();
    int getCurrentHighestScore();
    void resetCurrentScore();
    void increaseCurrentScore();
    void saveCurrentScore();

    // Moving Laser
    float getMovingLaserVelocity();

    // Laser Generator
    float getGenerateInterval(Difficulty difficulty);
    float getCurrentGenerateInterval();

    // Particle System
    ParticleSystemProp &getNormalLaserProp();

    // Window
    sf::Vector2u getWindowSize();
    sf::Vector2f getPointAtWindow(float x, float y);

    void setWindowSize(sf::Vector2u windowSize); //設定視窗寬高
};