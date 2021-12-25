#pragma once

#include <functional>

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Pantone : public GameObject
    {
    private:
        // Pantone State
        bool pressed; //是否被按
        bool hover;   //是否被覆蓋

        // Pantone Appearance
        int x, y, &points, &radius; //位置資訊
        float &hoverScale;          //覆蓋時縮放比例
        Color &color;               //顏色
        sf::ConvexShape leftConvex, rightConvex;

        // Pantone Click Event
        std::function<void()> onClick; //點擊事件

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

        // UI Update Function
        void setupShape();             //設定形狀
        void setHover(bool isHovered); //設定被覆蓋

    public:
        // Constructor & Deconstructor
        Pantone(sf::Vector2f position, int points, int radius, float hoverScale, Color &color, std::function<void()> onClick);

        // Accessors
        int &getRadius() const;                            //取得半徑
        void setColor(Color &color) override;              //取得顏色
        void setPosition(sf::Vector2f &position) override; //取得位置

        // Update Functions
        void updateMouseMove(sf::Vector2f &point) override;    //滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   //滑鼠按下
        void updateMouseRelease(sf::Vector2f &point) override; //滑鼠放開
    };
};