#include "Game/State/ColorState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Gameobject/ColorTile.h"
#include "Game/Game.h"

// Initializer
void ColorState::initUI()
{
    // Title 文字
    gameObjects["Title1"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 22),
        78,
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "CHOOSE THE COLOR");
    gameObjects["Title2"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 30),
        78,
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "COMBINATION YOU WANT");
    gameObjects["Exit"] = new GameObject::Button(
        game.setting.getPointAtWindow(94.5, 97),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "Exit",
        44,
        game.setting.getSoundBuffer(),
        [&]
        { Quit(); });
    // Tiles 容器
    int tileWidth = 150;                                                                                            //容器寬度
    int tileHeight = 140;                                                                                           //容器高度
    int minGap = 20;                                                                                                //容器之間的間距
    int validCount = int((game.setting.getWindowSize().x - borderSize * 2 - tileWidth) / (tileWidth + minGap)) + 1; //取得寬度的有效個數
    int gap = (game.setting.getWindowSize().x - borderSize * 2 - validCount * tileWidth) / (validCount - 1);        //取得兩側的 Gap

    int i = 0, counter = 0;
    int x = 100;
    int y = game.setting.getWindowSize().y * 35 / 100; //容器高度
    for (auto it : game.setting.getColorTable())
    {
        x = borderSize + (tileWidth + gap) * i;
        gameObjects[it.first] = new GameObject::ColorTile(
            sf::Vector2f(x, y),
            game.setting.getFont(),
            game.setting.findColor(it.first),
            game.setting.getSoundBuffer(),
            [=]
            { game.setColorTheme(it.first); });
        if (++i == validCount) //如果橫列滿了就下一列
        {
            i = 0;
            y += tileHeight;
        }
    }
}

ColorState::ColorState(Game &game) : State(game)
{
    initUI();
}