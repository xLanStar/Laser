#include "Game/State/PatternState.h"

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void PatternState::initUI()
{
    // Title
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 20),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "CHOOSE THE PATTERN\nYOU WANT");
    int minGap = game.setting.getTileGap();
    int tileWidth = game.setting.getTileWidth();
    int tileHeight = game.setting.getTileHeight();
    int borderSize = game.setting.getColorStateBorder();
    int validCount = int((game.setting.getWindowWidth() - borderSize * 2 - tileWidth) / (tileWidth + minGap)) + 1;
    int gap = (game.setting.getWindowWidth() - borderSize * 2 - validCount * tileWidth) / (validCount - 1);
    
    int i = 0, counter = 0;
    int x, y = 35 * game.setting.getWindowHeight() / 100;
    for(auto it : game.setting.getPatternTable())
    {
        x = borderSize + (tileWidth + gap) * i;
        gameObjects[it.first] = new GameObject::Button(
        sf::Vector2f(x+tileWidth/2, y+tileHeight/2),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        it.first,
        [=]{ game.setCursor(it.first); });
        if (++i == validCount)
        {
            i = 0;
            y += tileHeight;
        }
    }

}

// Constructor
PatternState::PatternState(Game &game) : State(game)
{
    initUI();
}

PatternState::~PatternState()
{
}

// Functions