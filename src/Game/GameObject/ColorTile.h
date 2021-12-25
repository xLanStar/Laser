#pragma once

#include "Game/GameObject/Text.h"
#include "Game/GameObject/Pantone.h"

namespace GameObject
{
    class ColorTile : public GameObject
    {
    private:
        // Tile Information
        sf::Vector2f &rect; //框架
        Text text;          //文字內容
        Pantone pantone;    //色票

        // Tile State
        bool pressed; //是否被按著
        bool hover;   //是否被覆蓋

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        // Constructor & Deconstructor
        ColorTile(sf::Vector2f position, sf::Vector2f &rect, int characterSize, sf::Font &font, int points, int radius, float hoverScale, Color &color, std::function<void()> onClick);

        // Accessors
        void setColor(Color &color) override;              //設定顏色
        void setPosition(sf::Vector2f &position) override; //設定位置

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;    //滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   //滑鼠點擊
        void updateMouseRelease(sf::Vector2f &point) override; //滑鼠放開
    };
}
