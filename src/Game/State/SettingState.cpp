#include "Game/State/SettingState.h"

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"

// UI Events

void SettingState::onColorButtonClick()
{
    std::cout << "Color Button Click!\n";
    game.pushState(COLOR);
}

void SettingState::onPatternButtonClick()
{
    std::cout << "Pattern Button Click!\n";
    game.pushState(PATTERN);
}


//Initializer
void SettingState::initUI()
{
    gameObjects["Color"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "Color",
        [&]{onColorButtonClick();});
    gameObjects["Pattern"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 60),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "Pattern",
        [&]{onPatternButtonClick();});
}

//Constructor
SettingState::SettingState(Game &game) : State(game)
{
    initUI();
}

// Functions
