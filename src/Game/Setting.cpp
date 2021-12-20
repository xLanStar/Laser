#include "Game/Setting.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "Game/GameObject/Pattern/Round.h"
#include "Game/GameObject/Pattern/Star.h"
#include "Game/Util.h"

Setting::Setting()
{
    if (!exist(colorFileName))
    {
        // Write Default Color Config
        std::ofstream outfile(colorFileName);

        outfile << "Pink\n255, 138, 188\n255, 202, 225";

        outfile.close();
    }

    // Read Color Config
    std::ifstream cFile(colorFileName, std::ifstream::in);
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

    // Font
    if (!font.loadFromFile("virgo.ttf"))
    {
        std::cout << "[Setting] load virgo.ttf failed!\n";
    }

    // Pattern
    patternTable["Round"] = new GameObject::Round(getColor(), getCursorSize(), (std::string) "Round");
    patternTable["Star"] = new GameObject::Star(getColor(), getCursorSize(), (std::string) "Star");

    // Default Window Size
    setWindowSize(sf::Vector2u(1280, 960));

    // load saving
    if (!load())
    {
        std::cout << "[Setting] load save fail!\n";

        // Set Default Color Theme
        setColorTheme("Pink");

        // Set Default Pattern
        setCursor("Star");
    }

    // Particle System
    normalLaserProp.loop = true;
    normalLaserProp.duration = 0.f;
    normalLaserProp.rateOverTime = 20.f;
    normalLaserProp.maxParticleCount = 10;
    normalLaserProp.size = 16.f;
    normalLaserProp.texture.loadFromFile("thunder.png");
    normalLaserProp.randomLifeTime = true;
    normalLaserProp.minLifeTimeRange = 0.5f;
    normalLaserProp.lifeTime = 1.0f;
    normalLaserProp.speed = 10.f;
    normalLaserProp.color = getColor().getDarkColor();
    normalLaserProp.fadeout = true;
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

    normalLaserProp.color = color.getDarkColor();

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

std::unordered_map<std::string, GameObject::Pattern *> &Setting::getPatternTable()
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
    cursor->setColor(getColor());
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
    if (getCurrentScore() > getCurrentHighestScore())
    {
        setHighestScore(getDifficulty(), getCurrentScore());
    }
}

// Game
int &Setting::getLaserBorderSize()
{
    return laserBorderSize;
}

// Laser
// Moving Laser
float &Setting::getMovingLaserVelocity()
{
    return movingLaserVelocity;
}

// Normal Laser
int &Setting::getNormalLaserLength()
{
    return normalLaserLength;
}

int &Setting::getNormalLaserThickness()
{
    return normalLaserThickness;
}

// PulseLaser
float &Setting::getPulseLaserDelay()
{
    return pulseLaserDelay;
}

float &Setting::getPulseLaserPowerTime()
{
    return pulseLaserPowerTime;
}

float &Setting::getPulseLaserDuration()
{
    return pulseLaserDuration;
}

int &Setting::getPulseLaserThickness()
{
    return pulseLaserThickness;
}

// Dash Line
int &Setting::getDashLineLength()
{
    return dashLineLength;
}

int &Setting::getDashLineThickness()
{
    return dashLineThickness;
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

// Particle System
ParticleSystemProp &Setting::getNormalLaserProp()
{
    return normalLaserProp;
}

// Window
sf::Vector2u &Setting::getWindowSize()
{
    return windowSize;
}

sf::FloatRect &Setting::getLaserBorderRect()
{
    return laserBorderRect;
}

sf::Vector2f Setting::getPointAtWindow(float x, float y)
{
    return sf::Vector2f(getWindowSize().x * x / 100,
                        getWindowSize().y * y / 100);
}

void Setting::setWindowSize(sf::Vector2u windowSize)
{
    this->windowSize = windowSize;

    // recalculate parameter
    movingLaserVelocity = sqrt(pow(windowSize.x, 2) + pow(windowSize.y, 2)) / 2.5f;

    laserBorderRect = sf::FloatRect(getLaserBorderSize(), getLaserBorderSize(), windowSize.x - getLaserBorderSize() * 2, windowSize.y - getLaserBorderSize() * 2);
}

// Save & Load
bool Setting::load()
{
    // if (exist(dataFileName))
    // {
    //     Data data;

    //     std::fstream infile(dataFileName, std::ios::binary | std::ios::in);

    //     if (infile.is_open())
    //     {
    //         infile.read((char *)&data, sizeof(data));

    //         infile.close();
    //     }

    //     for (int i = 0; i < 3; ++i)
    //     {
    //         highestScore[i] = data.highestScore[i];
    //     }

    //     std::cout << "[Setting] load ColorTheme: " << data.colorTheme;
    //     setColorTheme(data.colorTheme);

    //     std::cout << "[Setting] load CursorName: " << data.cursorName;
    //     setCursor(data.cursorName);
    //     return true;
    // }
    return false;
}

void Setting::save()
{
    // Data data;
    // for (int i = 0; i < 3; ++i)
    // {
    //     data.highestScore[i] = highestScore[i];
    // }

    // data.colorTheme = getColor().getName();

    // data.cursorName = getCursor()->getName();

    // std::fstream outfile(dataFileName, std::ios::binary | std::ios::out | std::ios::trunc);

    // outfile.write((char *)&data, sizeof(data));

    // outfile.close();
}

void Setting::debugParticleSystem1()
{
    normalLaserProp.rateOverTime += 15.f;
    if (normalLaserProp.rateOverTime >= 60.f)
    {
        normalLaserProp.rateOverTime -= 60.f;
    }
}