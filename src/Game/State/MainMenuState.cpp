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
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "PLAY",
        [&]{game.pushState(DIFFICULTY);});
    gameObjects["Setting"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 70),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "SETTING",
        [&]{game.pushState(SETTING);});
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94, 96),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "EXIT",
        [&]{Quit();});
    gameObjects["Producer"] = new GameObject::Button(
        game.setting.getPointAtWindow(13, 96),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "PRODUCER",
        [&]{game.pushState(PRODUCER);});
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