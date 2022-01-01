#include "Game/State/ExitState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void ExitState::initUI()
{
    gameObjects["Title1"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 43),
        84,
        game.setting.getColor(),
        game.setting.getFont(),
        "ARE YOU SURE TO");
    gameObjects["Title2"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 53),
        84,
        game.setting.getColor(),
        game.setting.getFont(),
        "QUIT THE GAME?");
    gameObjects["Yes"] = new GameObject::Button(
        game.setting.getPointAtWindow(40, 68),
        game.setting.getColor(),
        game.setting.getFont(),
        "YES",
        60,
        [&]
        { game.stop(); });
    gameObjects["No"] = new GameObject::Button(
        game.setting.getPointAtWindow(60, 68),
        game.setting.getColor(),
        game.setting.getFont(),
        "NO",
        60,
        [&]
        { Quit(); });
}

// Constructor
ExitState::ExitState(Game &game) : State(game)
{
    initUI();
}