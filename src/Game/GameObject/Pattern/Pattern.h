#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Color.h"
#include "Game/GameObject/Text.h"

namespace GameObject
{
    class Pattern : public GameObject
    {
    private:
        std::string name; // Pattern 的名稱

        // Pattern Appearance
        Color &color;           //對應的顏色
        int &radius;            //半徑長
        sf::CircleShape circle; //圓形

        // Pricate Function
        void setupShape(); //設定圖形

    public:
        // Constructor
        Pattern(Color &color, int &radius, std::string name);

        // Accessors
        std::string &getName();                        //取得 Pattern 的名稱
        int &getRadius();                              //取得半徑
        Color &getColor();                             //回傳顏色結構
        virtual void setColor(Color &color);           //設定顏色
        virtual void setPosition(sf::Vector2f &point); //設定位置

        // Update Events
        virtual void updateMouseMove(sf::Vector2f &point); //滑鼠移動

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染
    };
};