#include "Game/State/DifficultyState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void DifficultyState::initUI()
{
    gameObjects["Easy"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 35),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("EASY"),
        [&]
        { game.setting.setDifficulty(Difficulty::EASY); game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Normal"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 50),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        std::string("NORMAL"),
        [&]
        { game.setting.setDifficulty(Difficulty::NORMAL); game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Hard"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 65),
        game.setting.getButtonCharacterSize(),
        game.setting.getButtonHoverCharacterSize(),
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

// Functions