#include "Game/State/ReplayState.h"

#include "Game/Game.h"
#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Util.h"

//Initializer
void ReplayState::initUI()
{
    gameObjects["MVP"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "MVP:" + toString(game.setting.getCurrentHighestScore()));
    gameObjects["SCORE"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 40),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "SCORE:" + toString(game.setting.getCurrentScore()));
    gameObjects["Again"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 50),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "AGAIN",
        [&] { game.setting.resetCurrentScore(); game.switchState(GAME); });
    gameObjects["Menu"] = new GameObject::Button(
        game.setting.getPointAtWindow(50, 70),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "MENU",
        [&] { Quit(); });
}

//Constructor
ReplayState::ReplayState(Game &game) : State(game)
{
    initUI();
}