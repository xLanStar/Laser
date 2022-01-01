#pragma once

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Text : public GameObject
    {
    public:
        Text(sf::Vector2f position, int characterSize, Color &color, sf::Font &font, std::string str);

        sf::FloatRect getGlobalBounds() const;            // 取得邊界
        std::string getText() const;                      // 取得文字內容
        void setColor(Color &color) override;             // 設定顏色
        void setPosition(sf::Vector2f position) override; // 設定位置
        void setCharacterSize(int characterSize);         // 設定整個容器的大小
        void setText(std::string &str);                   // 設定文字

    private:
        sf::Text text; // 文字內容

        void draw(sf::RenderTarget &target, sf::RenderStates states) const; // 渲染
    };
}