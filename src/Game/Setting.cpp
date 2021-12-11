#include "Game/Setting.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

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
                Color color;
                color.name = line;

                // getline(cFile, line);
                // color.backgroundColor = stringToColor(line);

                getline(cFile, line);
                color.darkColor = stringToColor(line);

                getline(cFile, line);
                color.lightColor = stringToColor(line);

                ColorTable[color.name] = color;
                std::cout << "new ColorTheme: " << color.name << '\n';
            }
        }
    }
    else
    {
        std::cout << "open color.cfg failed!\n";
    }
    cFile.close();

    // Set Default Color Theme
    setColorTheme("Pink");

    // Font
    if (!font.loadFromFile("virgo.ttf"))
    {
        std::cout << "load virgo.ttf failed!\n";
    }
}

Setting::~Setting()
{
}

std::unordered_map<std::string, Color> &Setting::getColorTable()
{
    return ColorTable;
}
void Setting::setColorTheme(std::string colorTheme)
{
    color = ColorTable[colorTheme];
    std::cout << "set Color:" << color.name << '\n';
}

Color &Setting::findColor(std::string colorTheme)
{
    return ColorTable[colorTheme];
}

Color &Setting::getColor()
{
    return color;
}

int &Setting::getColorStateBorder()
{
    return colorStateBorder;
}

int &Setting::getColorTileGap()
{
    return colorTileGap;
}

int &Setting::getColorTileWidth()
{
    return colorTileWidth;
}

int &Setting::getColorTileHeight()
{
    return colorTileHeight;
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

GameObject::Pattern &Setting::getPattern()
{
    return pattern;
}

sf::Font &Setting::getFont()
{
    return font;
}

int &Setting::getTitleCharacterSize()
{
    return titleCharacterSize;
}

int &Setting::getButtonCharacterSize()
{
    return buttonCharacterSize;
}

int &Setting::getButtonHoverCharacterSize()
{
    return buttonHoverCharacterSize;
}

int &Setting::getWindowWidth()
{
    return windowWidth;
}

int &Setting::getWindowHeight()
{
    return windowHeight;
}

Point Setting::getPointAtWindow(float x, float y)
{
    return Point(getWindowWidth() * x / 100,
                 getWindowHeight() * y / 100);
}