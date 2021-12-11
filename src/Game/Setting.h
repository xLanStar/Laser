#pragma once

#include <unordered_map>

#include "Game/Color.h"
#include "Game/GameObject/Pattern.h"

class Setting
{
private:
    // Stored Theme Config
    std::unordered_map<std::string, Color> ColorTable;


    // Window Size
    int windowWidth = 1280, windowHeight = 720;


    // Color
    Color color;
    // Color Tile
    int colorStateBorder = 50, colorTileGap = 25, colorTileWidth = 250, colorTileHeight = 120;
    // Pantone
    int pantonePoints = 30, pantoneRadius = 32;
    float pantoneHoverScale = 1.2f;


    // TODO:Pattern
    GameObject::Pattern pattern;


    // Text
    int titleCharacterSize = 84; // Title
    int buttonCharacterSize = 48, buttonHoverCharacterSize = 64; // Button Text
    sf::Font font;

public:
    // Constructor & Deconstructor
    Setting();
    ~Setting();

    // Accessors
    std::unordered_map<std::string, Color> &getColorTable();
    void setColorTheme(std::string colorTheme);
    Color &findColor(std::string colorTheme);
    Color &getColor();
    int &getColorStateBorder();
    int &getColorTileGap();
    int &getColorTileWidth();
    int &getColorTileHeight();
    int &getPantonePoints();
    int &getPantoneRadius();
    float &getPantoneHoverScale();
    GameObject::Pattern &getPattern();
    sf::Font &getFont();
    int &getTitleCharacterSize();
    int &getButtonCharacterSize();
    int &getButtonHoverCharacterSize();

    // Screen Position
    int &getWindowWidth();
    int &getWindowHeight();
    Point getPointAtWindow(float x, float y);
};