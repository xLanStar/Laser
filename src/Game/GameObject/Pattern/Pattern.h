#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Color.h"
#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Pattern : public GameObject
    {
    public:
        // Constructor
        Pattern(Color &color, int &radius, std::string name, int boundRoundThickness = 12);

        // Getter
        const std::string &getName() const; //取得 Pattern 的名稱
        const int &getRadius() const;       //取得 Pattern 的半徑

        // Setter
        void setName();                                //設定 Pattern 的名稱
        void setRadius(int radius);                    //設定半徑
        virtual void setPosition(sf::Vector2f &point); //設定位置

        // Update Events
        virtual void updateMouseMove(sf::Vector2f &point); //滑鼠移動

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染
    protected:
        Color &color; //對應的顏色
        int &radius;  //半徑長

    private:
        int boundRoundThickness; //外圓線寬
        std::string name;        // Pattern 的名稱

        // Pattern Appearance
        sf::CircleShape boundRound; //圓形

        // Pricate Function
        void setupShape(); //設定圖形
    };
};