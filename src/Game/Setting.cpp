#include "Game/Setting.h"

#include <cmath>
#include <iostream>
#include <fstream>

#include "Game/Util.h"
#include "Game/GameObject/Pattern/Round.h"
#include "Game/GameObject/Pattern/Star.h"

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

    // Load Sound
    if (!soundBuffer.loadFromFile("ButtonSoundEffect.wav"))
    {
        std::cout << "[Setting] load ButtonSoundEffect.ogg failed\n";
    }

    // Font
    if (!font.loadFromFile("virgo.ttf"))
    {
        std::cout << "[Setting] load virgo.ttf failed!\n";
    }

    // Pattern
    patternTable["Round"] = new GameObject::Round(getColor(), "Round");
    patternTable["Star"] = new GameObject::Star(getColor(), "Star");

    // Default Window Size
    setWindowSize(sf::Vector2u(1280, 960));

    // Default Color Theme
    setColorTheme("Pink");

    // Particle System
    normalLaserProp.loop = true;
    normalLaserProp.duration = 1.f;
    normalLaserProp.rateOverTime = 20.f;
    normalLaserProp.maxParticleCount = 10;
    normalLaserProp.size = 16.f;
    normalLaserProp.randomLifeTime = true;
    normalLaserProp.minLifeTimeRange = 0.5f;
    normalLaserProp.lifeTime = 1.0f;
    normalLaserProp.speed = 50.f;
    normalLaserProp.color = getColor().getDarkColor();
    normalLaserProp.fadeout = true;

    // init Difficulty Table
    difficultyTable[EASY] = "Easy";
    difficultyTable[NORMAL] = "Normal";
    difficultyTable[HARD] = "Hard";
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
    pulseLaserProp.color = color.getDarkColor();

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

std::unordered_map<std::string, GameObject::Pattern *> &Setting::getPatternTable()
{
    return patternTable;
}

GameObject::Pattern *Setting::findCursor(std::string name)
{
    return patternTable[name];
}

sf::Font &Setting::getFont()
{
    return font;
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
int Setting::getHighestScore(Difficulty difficulty)
{
    return highestScore[difficulty];
}

void Setting::setHighestScore(Difficulty difficulty, int score)
{
    std::cout << "[Setting] set HightestScore difficulty: " << difficulty << " to " << score << '\n';
    highestScore[difficulty] = score;
}

int Setting::getCurrentScore()
{
    return currentScore;
}

int Setting::getCurrentHighestScore()
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

// Laser Generator
float Setting::getNormalLaserGenerateInterval(Difficulty difficulty)
{
    return normalLaserGenerateIntervals[difficulty];
}

float Setting::getCurrentNormalLaserGenerateInterval()
{
    return getNormalLaserGenerateInterval(getDifficulty());
}
float Setting::getPulseLaserGenerateInterval(Difficulty difficulty)
{
    return pulseLaserGenerateIntervals[difficulty];
}

float Setting::getCurrentPulseLaserGenerateInterval()
{
    return getPulseLaserGenerateInterval(getDifficulty());
}

// Particle System
ParticleSystemProp &Setting::getNormalLaserProp()
{
    return normalLaserProp;
}

ParticleSystemProp &Setting::getPulseLaserProp()
{
    return pulseLaserProp;
}

// Window
sf::Vector2u Setting::getWindowSize()
{
    return windowSize;
}

sf::Vector2f Setting::getPointAtWindow(float x, float y)
{
    return sf::Vector2f(getWindowSize().x * x / 100,
                        getWindowSize().y * y / 100);
}

void Setting::setWindowSize(sf::Vector2u windowSize)
{
    this->windowSize = windowSize;
}

std::string &Setting::getDifficultyName()
{
    return difficultyTable[difficulty];
}

sf::SoundBuffer &Setting::getSoundBuffer()
{
    return soundBuffer;
}