#pragma once

#include <unordered_map>
#include <cmath>

#include "Game/Color.h"
#include "Game/GameObject/Pattern.h"

enum Difficulty
{
    EASY = 0,
    NORMAL,
    HARD
};

class Setting
{
private:
    // Stored Theme Config
    std::unordered_map<std::string, Color> colorTable;

    // Pattern Table
    std::unordered_map<std::string, GameObject::Pattern*> patternTable;

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
    int titleCharacterSize = 84; // Title
    int subTitleCharacterSize = 64; // SubTitle
    int buttonCharacterSize = 48, buttonHoverCharacterSize = 64; // Button Text
    sf::Font font;

    // Difficulty
    Difficulty difficulty;

    // Game
    int gameBorderSize = 100;
    
    // Score
    int highestScore[3] = {0, 0, 0};
    int currentScore = 0;

    // Laser
    sf::Vector2f normalLaserRect = sf::Vector2f(300, 10);
    float movingLaserVelocity = sqrt(pow(getWindowWidth(), 2) + pow(getWindowHeight(), 2)) / 2.5f;

    // Laser Generator
    float generateIntervals[3] = {0.7f, 0.5f, 0.3f};
    
    // Window Size
    int windowWidth = 1280, windowHeight = 960;
    sf::Vector2f windowRect = sf::Vector2f(getWindowWidth(), getWindowHeight());
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
    std::unordered_map<std::string, GameObject::Pattern*> &getPatternTable();
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
    int &getGameBorderSize();

    // Laser
    sf::Vector2f &getNormalLaserRect();
    float &getMovingLaserVelocity();

    // Laser Generator
    float &getGenerateInterval(Difficulty difficulty);
    float &getCurrentGenerateInterval();

    // Window
    int &getWindowWidth();
    int &getWindowHeight();
    sf::Vector2f &getWindowRect();
    sf::Vector2f getPointAtWindow(float x, float y);
};