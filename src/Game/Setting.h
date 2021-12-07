#pragma once

#include <unordered_map>

#include "Game/Color.h"
#include "Game/Pattern.h"

enum ColorTheme
{
    Yellow, Pink, Blue, Cyan, Purple, Gray, Castella, Zebra
};

static std::unordered_map<std::string,ColorTheme> COLORTHEMETABLE = { {"Yellow",Yellow}, {"Pink",Pink}, {"Blue",Blue}, {"Cyan",Cyan}, {"Purple",Purple}, {"Gray",Gray}, {"Castella",Castella}, {"Zebra",Zebra} };

class Setting
{
private:
    // Stored Theme Config
    std::unordered_map<ColorTheme,Color> ColorTable;

    // Screen Size
    int screenWidth = 1280, screenHeight = 720;
    // Color
    Color color;

    // TODO:Pattern
    Pattern pattern;

    // Text
    int characterSize = 48, hoverCharacterSize = 64;
    sf::Font font;
public:
    Setting();
    ~Setting();

    void setColorTheme(ColorTheme colorTheme);
    Color &getColor();
    Pattern &getPattern();
    sf::Font &getFont();
    int getCharacterSize();
    int getHoverCharacterSize();
    int getScreenWidth();
    int getScreenHeight();
};