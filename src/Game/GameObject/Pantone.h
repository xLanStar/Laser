#pragma once

#include <functional>

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Pantone : public GameObject
    {
    public:
        Pantone(sf::Vector2f position, Color &color, std::function<void()> onClick, int points = 30, int radius = 32, float hoverScale = 1.2f);

        int getRadius() const;                            // 取得半徑
        void setPosition(sf::Vector2f position) override; // 取得位置

        void updateMouseMove(sf::Vector2f &point) override;    // 滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   // 滑鼠按下
        void updateMouseRelease(sf::Vector2f &point) override; // 滑鼠放開

    private:
        bool pressed;     // 是否被點擊
        bool hover;       // 是否被覆蓋
        int points;       // 多邊形的點數
        int radius;       // 色票的半徑
        float hoverScale; // 覆蓋時縮放比例

        sf::ConvexShape leftConvex, rightConvex; // 色票左右兩側的多邊形

        std::function<void()> onClick; // 點擊事件

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; // 渲染

        void setupShape(); // 設定形狀
    };
};