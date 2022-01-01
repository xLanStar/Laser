#pragma once

#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{
    class Star : public Pattern
    {
    public:
        Star(Color &color, std::string name);

        void setColor(Color &color) override;          //設定顏色
        void setPosition(sf::Vector2f point) override; //設定位置

        void updateMouseMove(sf::Vector2f &point) override; //滑鼠移動的觸發事件

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    private:
        sf::ConvexShape star; //星星圖案

        void setupShape(); //設定圖案
    };
}