#pragma once

#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{
    class Star : public Pattern
    {
    public:
        // Constructor
        Star(Color &color, std::string name);

        // Accessors
        void setColor(Color &color) override;          //設定顏色
        void setPosition(sf::Vector2f point) override; //設定位置

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        // Star Pattern Appearance
        float starSize;
        sf::ConvexShape star;

        // Pricate Function
        void setupShape();
    };
}