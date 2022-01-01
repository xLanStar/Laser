#include "Game/State/SettingState.h"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"

// UI Events

void SettingState::onColorButtonClick()
{
    game.pushState(COLOR);
}

void SettingState::onPatternButtonClick()
{
    game.pushState(PATTERN);
}

// Initializer
void SettingState::initUI()
{
    gameObjects["Color"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getColor(),
        game.setting.getFont(),
        "Color Setting",
        72,
        [&]
        { onColorButtonClick(); },
        1.1);
    gameObjects["Pattern"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 60),
        game.setting.getColor(),
        game.setting.getFont(),
        "Pattern Setting",
        72,
        [&]
        { onPatternButtonClick(); });
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        "Exit",
        44,
        [&]
        { Quit(); },
        1.1);
}

// Constructor
SettingState::SettingState(Game &game) : State(game)
{
    initUI();
}

// Functions
