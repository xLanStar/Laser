#include "Game/State/ReplayState.h"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Util.h"

// Initializer
void ReplayState::initUI()
{
    gameObjects["MVP"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 34),
        134,
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "MVP : " + toString(game.setting.getCurrentHighestScore()));
    gameObjects["Score"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 48),
        96,
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "Score : " + toString(game.setting.getCurrentScore()));
    gameObjects["Again"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 68),
        game.setting.getColor(),
        game.setting.getFont(),
        "AGAIN",
        50,
        game.setting.getSoundBuffer(),
        [&]
        { game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Menu"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 80),
        game.setting.getColor(),
        game.setting.getFont(),
        "MENU",
        50,
        game.setting.getSoundBuffer(),
        [&]
        { Quit(); });
}

// Constructor
ReplayState::ReplayState(Game &game) : State(game)
{
    initUI();
}