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
        "HOW TO PLAY:MOVE YOUR MOUSE AND TRY TO AVOID ALL SHOTS");
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
        std::string("EASY"),
        [&]
        { game.setting.setDifficulty(Difficulty::EASY); game.setting.resetCurrentScore(); game.switchState(GAME); },
        55);
    gameObjects["Normal"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 68),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("NORMAL"),
        [&]
        { game.setting.setDifficulty(Difficulty::NORMAL); game.setting.resetCurrentScore(); game.switchState(GAME); },
        55);
    gameObjects["Hard"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 81),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("HARD"),
        [&]
        { game.setting.setDifficulty(Difficulty::HARD); game.setting.resetCurrentScore(); game.switchState(GAME); },
        55);
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "EXIT",
        [&]
        { Quit(); },
        44);
}

// Constructor
DifficultyState::DifficultyState(Game &game) : State(game)
{
    initUI();
}