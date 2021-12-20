#pragma once

#include <unordered_map>
#include <cmath>

#include "Game/Color.h"
#include "Game/GameObject/Pattern/Pattern.h"
#include "Game/Particle/ParticleSystemProp.h"

struct Data
{
    int highestScore[3];
    std::string colorTheme;
    std::string cursorName;
};

enum Difficulty
{
    EASY = 0,
    NORMAL,
    HARD
};

static std::string dataFileName = "data.bin";
static std::string colorFileName = "color.cfg";

class Setting
{
private:
    // Stored Theme Config
    std::unordered_map<std::string, Color> colorTable;

    // Pattern Table
    std::unordered_map<std::string, GameObject::Pattern *> patternTable;

    // Color
    Color color;

    // Color State
    int colorStateBorder = 50;

    // Tile
    int tileGap = 25, tileWidth = 250, tileHeight = 120;
    sf::Vector2f tileRect = sf::Vector2f(getTileWidth(), getTileHeight());

    // Pantone
    int pantonePoints = 30, pantoneRadius = 32;
    float pantoneHoverScale = 1.2f;

    // Cursor
    int cursorSize = 48;
    GameObject::Pattern *cursor;

    // Text
    int titleCharacterSize = 84;                                 // Title
    int subTitleCharacterSize = 64;                              // SubTitle
    int buttonCharacterSize = 48, buttonHoverCharacterSize = 64; // Button Text
    sf::Font font;

    // Difficulty
    Difficulty difficulty;

    // Game
    int laserBorderSize = 100;
    sf::FloatRect laserBorderRect;

    // Score
    int highestScore[3] = {0, 0, 0};
    int currentScore = 0;

    // Laser
    // - Moving Laser
    float movingLaserVelocity;
    // - Normal Laser
    int normalLaserLength = 200;
    int normalLaserThickness = 10;
    // - Pulse Laser
    float pulseLaserDelay = 0.5f;
    float pulseLaserPowerTime = 0.1f;
    float pulseLaserDuration = 0.5f;
    int pulseLaserThickness = 25;

    // Dash Line
    int dashLineLength = 75;
    int dashLineThickness = 10;

    // Laser Generator
    float generateIntervals[3] = {0.7f, 0.5f, 0.3f};

    // Particle System
    ParticleSystemProp normalLaserProp;

    // Window Size
    sf::Vector2u windowSize;

public:
    // Constructor & Deconstructor
    Setting();
    ~Setting();

    // Accessors
    // Color
    std::unordered_map<std::string, Color> &getColorTable();
    void setColorTheme(std::string colorTheme);
    Color &findColor(std::string colorTheme);
    Color &getColor();

    // Color State
    int &getColorStateBorder();

    // Tile
    int &getTileGap();
    int &getTileWidth();
    int &getTileHeight();
    sf::Vector2f &getTileRect();

    // Patone
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

    void setWindowSize(sf::Vector2u windowSize);

    // Save & Load
    bool load();
    void save();

    // DEBUG
    void debugParticleSystem1();
};