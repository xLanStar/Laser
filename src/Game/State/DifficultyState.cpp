#include "Game/State/DifficultyState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void DifficultyState::initUI()
{
    gameObjects["Tutorial"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 2.5),
        28,
        game.setting.getColor(),
        game.setting.getFont(),
        "HOW TO PLAY : MOVE YOUR MOUSE AND TRY TO AVOID ALL SHOTS");
    gameObjects["Title1"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 27),
        84,
        game.setting.getColor(),
        game.setting.getFont(),
        "CHOOSE THE MODE");
    gameObjects["Title2"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 36),
        84,
        game.setting.getColor(),
        game.setting.getFont(),
        "YOU WANT");
    gameObjects["Easy"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 55),
        game.setting.getColor(),
        game.setting.getFont(),
        "EASY",
        55,
        [&]
        { game.setting.setDifficulty(Difficulty::EASY); game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Normal"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 68),
        game.setting.getColor(),
        game.setting.getFont(),
        "NORMAL",
        55,
        [&]
        { game.setting.setDifficulty(Difficulty::NORMAL); game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Hard"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 81),
        game.setting.getColor(),
        game.setting.getFont(),
        "HARD",
        55,
        [&]
        { game.setting.setDifficulty(Difficulty::HARD); game.setting.resetCurrentScore(); game.switchState(GAME); });
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
DifficultyState::DifficultyState(Game &game) : State(game)
{
    initUI();
}