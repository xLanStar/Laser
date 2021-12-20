#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Color.h"
#include "Game/GameObject/Text.h"

namespace GameObject
{
    class Pattern : public GameObject
    {
    private:
        std::string name;

        // Pattern Appearance
        Color &color;           //對應的顏色
        int &radius;            //半徑長
        sf::CircleShape circle; //圓形

        // Pricate Function
        void setupShape();

    public:
        // Constructor
        Pattern(Color &color, int &radius, std::string name);
        ~Pattern();

        // Accessors
        std::string &getName();
        int &getRadius();
        Color &getColor();                             //回傳顏色結構
        virtual void setColor(Color &color);           //設定顏色
        virtual void setPosition(sf::Vector2f &point); //設定位置

        // Update Events
        virtual void updateMouseMove(sf::Vector2f &point);
        virtual void updateMousePress(sf::Vector2f &point);
        virtual void updateMouseRelease(sf::Vector2f &point);
        virtual void update(float &deltaTime); //更新

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染
    };
};