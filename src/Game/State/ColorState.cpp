#include "Game/State/ColorState.h"

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Gameobject/ColorTile.h"
#include "Game/Game.h"

// Initializer
void ColorState::initUI()
{
    // Title
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 20),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "CHOOSE THE COLOR\nCOMBINATION YOU WANT");
    // Tiles
    int &points = game.setting.getPantonePoints();
    int &radius = game.setting.getPantoneRadius();
    int &borderSize = game.setting.getColorStateBorder();
    int tileWidth = game.setting.getTileWidth();
    int tileHeight = game.setting.getTileHeight();
    int &minGap = game.setting.getTileGap();
    int validCount = int((game.setting.getWindowSize().x - borderSize * 2 - tileWidth) / (tileWidth + minGap)) + 1;
    int gap = (game.setting.getWindowSize().x - borderSize * 2 - validCount * tileWidth) / (validCount - 1);

    int i = 0, counter = 0;
    int x, y = 35 * game.setting.getWindowSize().y / 100;
    for (auto it : game.setting.getColorTable())
    {
        x = borderSize + (tileWidth + gap) * i;
        gameObjects[it.first] = new GameObject::ColorTile(
        sf::Vector2f(x, y),
        game.setting.getTileRect(),
        game.setting.getButtonCharacterSize(),
        game.setting.getFont(),
        game.setting.getPantonePoints(),
        game.setting.getPantoneRadius(),
        game.setting.getPantoneHoverScale(),
        game.setting.findColor(it.first),
        [=]{ game.setColorTheme(it.first); });
        if (++i == validCount)
        {
            i = 0;
            y += tileHeight;
        }
    }
}

// Constructor
ColorState::ColorState(Game &game) : State(game)
{
    initUI();
}

// Functions