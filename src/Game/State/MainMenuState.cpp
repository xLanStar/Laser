#include "Game/State/MainMenuState.h"

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Gameobject/PatternTile.h"

// UI Events

void MainMenuState::onPlayButtonClick()
{
    std::cout << "Play Button Click!\n";
}

void MainMenuState::onSettingButtonClick()
{
    std::cout << "Setting Button Click!\n";
    game.pushState(SETTING);
}


//Initializer
void MainMenuState::initUI()
{
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        game.setting.getTitleCharacterSize(),
        game.setting.getFont(),
        (std::string) "THUNDER LASER");
    gameObjects["Play"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 50),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getFont(),
        (std::string) "PLAY",
        [&]{onPlayButtonClick();});
    gameObjects["Setting"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 70),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getFont(),
        (std::string) "SETTING",
        [&]{onSettingButtonClick();});
}

//Constructor
MainMenuState::MainMenuState(Game &game) : State(game)
{
    initUI();
}

MainMenuState::~MainMenuState()
{

}

// Functions
void MainMenuState::Quit()
{
    game.pushState(EXIT);
}