#pragma once

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Text : public GameObject
    {
    private:
        // Text Appearance
        sf::Font &font; //字形
        sf::Text text;  //文字內容

        // UI Draw Function
        void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        // Constructor & Deconstructor
        Text(sf::Vector2f position, int &characterSize, Color &color, sf::Font &font, std::string str);

        // Accessors
        sf::FloatRect getGlobalBounds();                   //取得外框邊界
        std::string getText();                             //取得文字內容
        sf::Font &getFont();                               //取得字形
        void setColor(Color &color) override;              //設定顏色
        void setPosition(sf::Vector2f &position) override; //設定位置
        void setCharacterSize(int &characterSize);         //設定字元大小
        void setText(std::string &str);                    //設定文字
        void setFont(sf::Font &font);                      //設定字形
    };
}