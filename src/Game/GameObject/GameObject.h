#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Color.h"

namespace GameObject
{
    class GameObject : public sf::Drawable
    {
    public:
        GameObject(Color &color, sf::Vector2f position = sf::Vector2f(0, 0));

        sf::Vector2f getPosition() const; //取得位置

        virtual void setPosition(sf::Vector2f position);        // 設定位置
        virtual void setColor(Color &color);                    // 設定顏色
        virtual void updateMouseMove(sf::Vector2f &point){};    // 滑鼠移動
        virtual void updateMousePress(sf::Vector2f &point){};   // 滑鼠按下
        virtual void updateMouseRelease(sf::Vector2f &point){}; // 滑鼠放開
        virtual void update(float deltaTime){};                 // 更新

    protected:
        Color &color;          // 顏色
        sf::Vector2f position; // 位置
    };
}