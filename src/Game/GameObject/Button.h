#pragma once

#include <functional>

#include "Game/GameObject/Text.h"
/**
enum button_states
{
    BTN_IDLE,
    BTN_HOVER,
    BTN_ACTIVE
};
**/

namespace GameObject
{
    class Button : public GameObject
    {
    private:
        // Button State
        bool pressed; //是否滑鼠按著
        bool hover;   //是否物件被點擊

        // Button Appearance
        Text text;                               //文字
        int &characterSize, &hoverCharacterSize; //字元大小和被 hover 時的字元大小

        // Button event
        std::function<void()> onClick; //被點擊時要觸發的 function

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

        // UI Update Function
        void setHover(bool isHovered); //設定覆蓋狀態

    public:
        // Constructor
        Button(sf::Vector2f position, int &characterSize, int &hoverCharacterSize, Color &color, sf::Font &font, std::string str, std::function<void()> onClick);

        // Accessors
        void setColor(Color &color) override;              //設定顏色
        void setPosition(sf::Vector2f &position) override; //設定位置

        // Update Functions
        void updateMouseMove(sf::Vector2f &point) override;    //滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   //滑鼠按下
        void updateMouseRelease(sf::Vector2f &point) override; //滑鼠放開
        void update(float &deltaTime) override;                //更新
    };
};