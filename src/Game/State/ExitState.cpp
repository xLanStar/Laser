#include "Game/State/ExitState.h"

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

//Initializer
void ExitState::initUI()
{
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "ARE YOU SURE TO\nQUIT THE GAME?");
    gameObjects["Yes"] = new GameObject::Button(
        game.setting.getPointAtWindow(40, 60),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "YES",
        [&]{game.stop();});
    gameObjects["No"] = new GameObject::Button(
        game.setting.getPointAtWindow(60, 60),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "NO",
        [&]{Quit();});
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