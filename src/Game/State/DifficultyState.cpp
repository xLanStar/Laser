#include "Game/State/DifficultyState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void DifficultyState::initUI()
{
    gameObjects["Tutorial"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 4),
        28,
        game.setting.getColor(),
        game.setting.getFont(),
        "HOW TO PLAY:MOVE YOUR MOUSE AND TRY TO AVOID ALL SHOTS");
    gameObjects["Title1"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 20),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "CHOOSE THE DIFFICULTY");
    gameObjects["Title2"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        "YOU WANT");
    gameObjects["Easy"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 50),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("EASY"),
        [&]
        { game.setting.setDifficulty(Difficulty::EASY); game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Normal"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 60),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("NORMAL"),
        [&]
        { game.setting.setDifficulty(Difficulty::NORMAL); game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Hard"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 70),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("HARD"),
        [&]
        { game.setting.setDifficulty(Difficulty::HARD); game.setting.resetCurrentScore(); game.switchState(GAME); });
}

// Constructor
DifficultyState::DifficultyState(Game &game) : State(game)
{
    initUI();
}