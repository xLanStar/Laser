#include "Game/State/MainMenuState.h"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"

//Initializer
void MainMenuState::initUI()
{
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "THUNDER LASER");
    gameObjects["Play"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 50),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "PLAY",
        [&]{game.pushState(DIFFICULTY);});
    gameObjects["Setting"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 70),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "SETTING",
        [&]{game.pushState(SETTING);});
}

//Constructor
MainMenuState::MainMenuState(Game &game) : State(game)
{
    initUI();
}

// Functions
void MainMenuState::Quit()
{
    game.pushState(EXIT);
}