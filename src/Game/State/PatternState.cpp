#include "Game/State/PatternState.h"

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Gameobject/ColorTile.h"
#include "Game/Game.h"

// Initializer
void PatternState::initUI()
{
    // Title
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 20),
        game.setting.getTitleCharacterSize(),
        game.setting.getFont(),
        (std::string) "CHOOSE THE PATTERN\nYOU WANT");
    //TODO:
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