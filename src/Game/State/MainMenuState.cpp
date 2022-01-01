#include "Game/State/MainMenuState.h"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"

// Initializer
void MainMenuState::initUI()
{
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 29),
        109,
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "THUNDER LASER");
    gameObjects["Play"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 53),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "PLAY",
        [&]
        { game.pushState(DIFFICULTY); },
        67);
    gameObjects["Setting"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 73),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "SETTING",
        [&]
        { game.pushState(SETTING); },
        67);
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "EXIT",
        [&]
        { Quit(); },
        44);
    gameObjects["Producer"] = new GameObject::Button(
        game.setting.getPointAtWindow(12, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "PRODUCER",
        [&]
        { game.pushState(PRODUCER); },
        44);
}

// Constructor
MainMenuState::MainMenuState(Game &game) : State(game)
{
    initUI();
}

// Functions
void MainMenuState::Quit()
{
    game.pushState(EXIT);
}