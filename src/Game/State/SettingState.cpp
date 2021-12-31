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


//Initializer
void SettingState::initUI()
{
    gameObjects["Color"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "Color",
        [&]{onColorButtonClick();});
    gameObjects["Pattern"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 60),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "Pattern",
        [&]{onPatternButtonClick();});
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94, 96),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "EXIT",
        [&]{Quit();});
}

//Constructor
SettingState::SettingState(Game &game) : State(game)
{
    initUI();
}

// Functions
