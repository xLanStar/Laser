#include "Game/Setting.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "Game/GameObject/Pattern/Round.h"
#include "Game/GameObject/Pattern/Star.h"

sf::Color stringToColor(std::string string)
{
    // Split String with ,
    // Red, Green, Blue
    std::stringstream ss(string);
    std::string temp = "";
    int colorBytes[3];

    for (int i = 0; i < 3; ++i)
    {
        std::getline(ss, temp, ',');
        colorBytes[i] = atoi(temp.c_str());
    }

    // return Color(Red, Green, Blue);
    return sf::Color(colorBytes[0], colorBytes[1], colorBytes[2]);
}

Setting::Setting()
{
    // Read Color Config
    std::ifstream cFile("color.cfg", std::ifstream::in);
    if (cFile.is_open())
    {
        std::string line;
        while (getline(cFile, line))
        {
            if (!line.empty())
            {
                std::string name = line;

                getline(cFile, line);
                sf::Color darkColor = stringToColor(line);

                getline(cFile, line);
                sf::Color lightColor = stringToColor(line);

                colorTable[name] = Color(name, darkColor, lightColor);
                std::cout << "[Setting] found new ColorTheme: " << name << '\n';
            }
        }
    }
    else
    {
        std::cout << "[Setting] open color.cfg failed!\n";
    }
    cFile.close();

    // Set Default Color Theme
    setColorTheme("Pink");

    // Font
    if (!font.loadFromFile("virgo.ttf"))
    {
        std::cout << "[Setting] load virgo.ttf failed!\n";
    }

    // Pattern
    patternTable["Round"] = new GameObject::Round(getColor(), getCursorSize(), (std::string)"Round");
    patternTable["Star"] = new GameObject::Star(getColor(), getCursorSize(), (std::string)"Star");
    
    // Set Default Pattern
    setCursor("Star");

    movingLaserVelocity = sqrt(pow(getWindowWidth() - getGameBorderSize(), 2) + pow(getWindowHeight() - getGameBorderSize(), 2)) / 2.5f;
}

Setting::~Setting()
{
}

std::unordered_map<std::string, Color> &Setting::getColorTable()
{
    return colorTable;
}

void Setting::setColorTheme(std::string colorTheme)
{
    color = colorTable[colorTheme];
    std::cout << "[Setting] set Color to " << color.getName() << '\n';
}

Color &Setting::findColor(std::string colorTheme)
{
    return colorTable[colorTheme];
}

Color &Setting::getColor()
{
    return color;
}

int &Setting::getColorStateBorder()
{
    return colorStateBorder;
}

int &Setting::getTileGap()
{
    return tileGap;
}

int &Setting::getTileWidth()
{
    return tileWidth;
}

int &Setting::getTileHeight()
{
    return tileHeight;
}

sf::Vector2f &Setting::getTileRect()
{
    return tileRect;
}

int &Setting::getPantonePoints()
{
    return pantonePoints;
}

int &Setting::getPantoneRadius()
{
    return pantoneRadius;
}

float &Setting::getPantoneHoverScale()
{
    return pantoneHoverScale;
}

std::unordered_map<std::string, GameObject::Pattern*> &Setting::getPatternTable()
{
    return patternTable;
}

GameObject::Pattern *Setting::findCursor(std::string name)
{
    return patternTable[name];
}

int &Setting::getCursorSize()
{
    return cursorSize;
}

GameObject::Pattern *Setting::getCursor()
{
    return cursor;
}

void Setting::setCursor(std::string name)
{
    std::cout << "[Setting] set Cursor to " << name << '\n';
    cursor = findCursor(name);
}

sf::Font &Setting::getFont()
{
    return font;
}

int &Setting::getTitleCharacterSize()
{
    return titleCharacterSize;
}

int &Setting::getSubTitleCharacterSize()
{
    return subTitleCharacterSize;
}

int &Setting::getButtonCharacterSize()
{
    return buttonCharacterSize;
}

int &Setting::getButtonHoverCharacterSize()
{
    return buttonHoverCharacterSize;
}

// Difficulty
Difficulty &Setting::getDifficulty()
{
    return difficulty;
}

void Setting::setDifficulty(Difficulty difficulty)
{
    std::cout << "[Setting] set Difficulty to " << difficulty << '\n';
    this->difficulty = difficulty;
}

// Score
int &Setting::getHighestScore(Difficulty difficulty)
{
    return highestScore[difficulty];
}

void Setting::setHighestScore(Difficulty difficulty, int score)
{
    std::cout << "[Setting] set HightestScore difficulty: " << difficulty << " to " << score << '\n';
    highestScore[difficulty] = score;
}

int &Setting::getCurrentScore()
{
    return currentScore;
}

int &Setting::getCurrentHighestScore()
{
    return getHighestScore(getDifficulty());
}

void Setting::resetCurrentScore()
{
    currentScore = 0;
}

void Setting::increaseCurrentScore()
{
    currentScore++;
}

void Setting::saveCurrentScore()
{
    if(getCurrentScore() > getCurrentHighestScore())
    {
        setHighestScore(getDifficulty(), getCurrentScore());
    }
}

// Game
int &Setting::getGameBorderSize()
{
    return gameBorderSize;
}

// Laser
sf::Vector2f &Setting::getNormalLaserRect()
{
    return normalLaserRect;
}

float &Setting::getMovingLaserVelocity()
{
    return movingLaserVelocity;
}

// Laser Generator
float &Setting::getGenerateInterval(Difficulty difficulty)
{
    return generateIntervals[difficulty];
}

float &Setting::getCurrentGenerateInterval()
{
    return getGenerateInterval(getDifficulty());
}

// Window
int &Setting::getWindowWidth()
{
    return windowWidth;
}

int &Setting::getWindowHeight()
{
    return windowHeight;
}

sf::Vector2f &Setting::getWindowRect()
{
    return windowRect;
}

sf::Vector2f Setting::getPointAtWindow(float x, float y)
{
    return sf::Vector2f(getWindowWidth() * x / 100,
                        getWindowHeight() * y / 100);
}