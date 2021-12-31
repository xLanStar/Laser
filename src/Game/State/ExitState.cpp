#include "Game/State/ExitState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void ExitState::initUI()
{
    gameObjects["Title1"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "ARE YOU SURE TO");
    gameObjects["Title2"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 50),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "QUIT THE GAME?");
    gameObjects["Yes"] = new GameObject::Button(
        game.setting.getPointAtWindow(40, 60),
        game.setting.getColor(),
        game.setting.getFont(),
        "YES",
        [&]
        { game.stop(); });
    gameObjects["No"] = new GameObject::Button(
        game.setting.getPointAtWindow(60, 60),
        game.setting.getColor(),
        game.setting.getFont(),
        "NO",
        [&]
        { Quit(); });
}

// Constructor
ExitState::ExitState(Game &game) : State(game)
{
    initUI();
}