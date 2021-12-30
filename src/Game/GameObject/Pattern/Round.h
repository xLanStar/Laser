#pragma once

#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{

    class Round : public Pattern
    {
    public:
        // Constructor
        Round(Color &color, std::string name);

        // Accessors
        void setColor(Color &color) override;          //設定顏色
        void setPosition(sf::Vector2f point) override; //設定位置

        // Update Events
        void updateMouseMove(sf::Vector2f &position) override;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        // Round Pattern Appearance
        sf::CircleShape round;

        // Pricate Function
        void setupShape();
    };
}