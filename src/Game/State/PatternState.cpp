#include "Game/State/PatternState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Game.h"

// Initializer
void PatternState::initUI()
{
    // Title
    gameObjects["Title1"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 22),
        78,
        game.setting.getColor(),
        game.setting.getFont(),
        "CHOOSE THE PATTERN");
    gameObjects["Title2"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        78,
        game.setting.getColor(),
        game.setting.getFont(),
        "YOU WANT");
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        "Exit",
        44,
        [&]
        { Quit(); });
    int tileWidth = 250;  //容器寬度
    int tileHeight = 120; //容器高度
    int minGap = 25;      //容器之間的間距
    int validCount = int((game.setting.getWindowSize().x - borderSize * 2 - tileWidth) / (tileWidth + minGap)) + 1;
    int gap = (game.setting.getWindowSize().x - borderSize * 2 - validCount * tileWidth) / (validCount - 1);

    int i = 0, counter = 0;
    int x, y = 35 * game.setting.getWindowSize().y / 100;
    for (auto it : game.setting.getPatternTable())
    {
        x = borderSize + (tileWidth + gap) * i;
        gameObjects[it.first] = new GameObject::Button(
            sf::Vector2f(x + tileWidth / 2, y + tileHeight / 2),
            game.setting.getColor(),
            game.setting.getFont(),
            it.first,
            48,
            [=]
            { game.setCursor(it.first); });
        if (++i == validCount)
        {
            i = 0;
            y += tileHeight;
        }
    }
}

// Constructor
PatternState::PatternState(Game &game) : State(game)
{
    initUI();
}

// Functions