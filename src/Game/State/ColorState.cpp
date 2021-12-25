#include "Game/State/ColorState.h"

#include "Game/Gameobject/Button.h"
#include "Game/Gameobject/Text.h"
#include "Game/Gameobject/ColorTile.h"
#include "Game/Game.h"

// Initializer
void ColorState::initUI()
{
    // Title 文字
    gameObjects["Title"] = new GameObject::Text(
        game.setting.getPointAtWindow(50, 20),
        game.setting.getTitleCharacterSize(),
        game.setting.getColor(),
        game.setting.getFont(),
        (std::string) "CHOOSE THE COLOR\nCOMBINATION YOU WANT");
    // Tiles 容器
    int &points = game.setting.getPantonePoints();                                                                  //取得座標
    int &radius = game.setting.getPantoneRadius();                                                                  //取得色票大小
    int &borderSize = game.setting.getColorStateBorder();                                                           //取得邊界寬度
    int tileWidth = game.setting.getTileWidth();                                                                    //取得容器寬度
    int tileHeight = game.setting.getTileHeight();                                                                  //取得容器高度
    int &minGap = game.setting.getTileGap();                                                                        //取得容器之間的間距
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
            game.setting.getTileRect(),
            game.setting.getButtonCharacterSize(),
            game.setting.getFont(),
            game.setting.getPantonePoints(),
            game.setting.getPantoneRadius(),
            game.setting.getPantoneHoverScale(),
            game.setting.findColor(it.first),
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