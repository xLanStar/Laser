#pragma once

#include <functional>

#include "Game/GameObject/Text.h"

namespace GameObject
{
    class Button : public GameObject
    {
    private:
        // Button State
        bool pressed; //是否滑鼠按著
        bool hover;   //是否物件被點擊

        // Button Appearance
        int buttonCharacterSize, buttonHoverCharacterSize;
        Text text;           //文字
        int characterSize;   //字元大小
        int characterScaler; //放大倍率

        // Button event
        std::function<void()> onClick; //被點擊時要觸發的 function

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        // Constructor
        Button(sf::Vector2f position, Color &color, sf::Font &font, std::string str, int characterSize, std::function<void()> onClick, int characterScaler = 1.3);

        // Accessors
        void setColor(Color &color) override;             //設定顏色
        void setPosition(sf::Vector2f position) override; //設定位置

        // Update Functions
        void updateMouseMove(sf::Vector2f &point) override;    //滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   //滑鼠按下
        void updateMouseRelease(sf::Vector2f &point) override; //滑鼠放開
        void update(float deltaTime) override;                 //更新
    };
};