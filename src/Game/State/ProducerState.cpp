#include "Game/State/ProducerState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void ProducerState::initUI()
{
    gameObjects["Code"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 18),
        82,
        game.setting.getColor(),
        game.setting.getFont(),
        "Code");
    gameObjects["CoderList"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 36),
        76,
        game.setting.getColor(),
        game.setting.getFont(),
        "x.LanStar\nNinja Code");
    gameObjects["Art"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 58),
        82,
        game.setting.getColor(),
        game.setting.getFont(),
        "Art");
    gameObjects["ArtList"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 78),
        76,
        game.setting.getColor(),
        game.setting.getFont(),
        "x.LanStar\nNinja Code");
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        "EXIT",
        44,
        [&]
        { Quit(); });
}

// Constructor
ProducerState::ProducerState(Game &game) : State(game)
{
    initUI();
}