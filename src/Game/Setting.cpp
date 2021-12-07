#include "Game/Setting.h"

#include <iostream>
#include <fstream>
#include <sstream>

const ColorTheme getColorTheme(std::string colorName)
{
    return COLORTHEMETABLE[colorName];
}

sf::Color stringToColor(std::string string)
{
    // Split String with ,
    std::stringstream ss(string);
    std::string temp = "";
    int colorBytes[3];
    for (int i = 0; i < 3; ++i)
    {
        std::getline(ss, temp, ',');
        colorBytes[i] = atoi(temp.c_str());
    }
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
            if (COLORTHEMETABLE.find(line) != COLORTHEMETABLE.end())
            {
                ColorTheme colorTheme = COLORTHEMETABLE[line];
                Color color;
                //getline(cFile, line);
                //color.backgroundColor = stringToColor(line);
                getline(cFile, line);
                color.darkColor = stringToColor(line);
                getline(cFile, line);
                color.lightColor = stringToColor(line);
                ColorTable[colorTheme] = color;
            }
        }
        setColorTheme(ColorTheme::Pink); // Default Color Theme
    }
    else
    {
        std::cout << "open color.cfg failed!\n";
    }

    // Font
    if (!font.loadFromFile("virgo.ttf"))
    {
        std::cout << "load virgo.ttf failed!\n";
    }
}

Setting::~Setting()
{
}

void Setting::setColorTheme(ColorTheme colorTheme)
{
    color = ColorTable[colorTheme];
}

Color &Setting::getColor()
{
    return color;
}

Pattern &Setting::getPattern()
{
    return pattern;
}

sf::Font &Setting::getFont()
{
    return font;
}

int Setting::getCharacterSize()
{
    return characterSize;
}

int Setting::getHoverCharacterSize()
{
    return hoverCharacterSize;
}

int Setting::getScreenWidth()
{
    return screenWidth;
}

int Setting::getScreenHeight()
{
    return screenHeight;
}