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
        "PLAY",
        67,
        [&]
        { game.pushState(DIFFICULTY); });
    gameObjects["Setting"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 73),
        game.setting.getColor(),
        game.setting.getFont(),
        "SETTING",
        67,
        [&]
        { game.pushState(SETTING); });
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        "EXIT",
        44,
        [&]
        { Quit(); });
    gameObjects["Producer"] = new GameObject::Button(
        game.setting.getPointAtWindow(12, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        "PRODUCER",
        44,
        [&]
        { game.pushState(PRODUCER); });
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