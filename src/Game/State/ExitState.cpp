#include "Game/State/ExitState.h"

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// UI Events

void ExitState::onYesButtonClick()
{
    std::cout << "Yes Button Click!\n";
    game.stop();
}

void ExitState::onNoButtonClick()
{
    std::cout << "No Button Click!\n";
    Quit();
}


//Initializer
void ExitState::initUI()
{
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getTitleCharacterSize(),
        game.setting.getFont(),
        (std::string) "ARE YOU SURE TO\nQUIT THE GAME?");
    gameObjects["Yes"] = new GameObject::Button(
        game.setting.getPointAtWindow(40, 60),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getFont(),
        (std::string) "YES",
        [&]{onYesButtonClick();});
    gameObjects["No"] = new GameObject::Button(
        game.setting.getPointAtWindow(60, 60),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getFont(),
        (std::string) "NO",
        [&]{onNoButtonClick();});
}

//Constructor
ExitState::ExitState(Game &game) : State(game)
{
    initUI();
}

ExitState::~ExitState()
{

}

// Functions