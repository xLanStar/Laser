#include "Game/State/ProducerState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void ProducerState::initUI()
{
    gameObjects["Code"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 20),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "CODE");
    gameObjects["A"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "A");
    gameObjects["ART"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 60),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "ART");
    gameObjects["Y.DOOG"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 70),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "Y.DOOG");
    gameObjects["JTT.YANG"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 80),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "JTT.YANG");
}

// Constructor
ProducerState::ProducerState(Game &game) : State(game)
{
    initUI();
}