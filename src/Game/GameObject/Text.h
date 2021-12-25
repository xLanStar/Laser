#pragma once

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Text : public GameObject
    {
    private:
        sf::Font &font; //字形資訊
        sf::Text text;  //文字內容

        void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        // Constructor & Deconstructor
        Text(sf::Vector2f position, int &characterSize, Color &color, sf::Font &font, std::string str);

        // Accessors
        sf::FloatRect getGlobalBounds() const;             //取得外框邊界
        std::string getText() const;                       //取得文字內容
        void setColor(Color &color) override;              //設定顏色
        void setPosition(sf::Vector2f &position) override; //設定位置
        void setCharacterSize(int &characterSize);         //設定整個容器的大小
        void setText(std::string &str);                    //設定文字
        void setFont(sf::Font &font);                      //設定字形資訊
    };
}