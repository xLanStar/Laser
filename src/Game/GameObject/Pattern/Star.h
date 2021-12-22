#pragma once

#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{

    class Star : public Pattern
    {
    private:
        // Star Pattern Appearance
        float starSize;
        sf::ConvexShape star;

        // Pricate Function
        void setupShape();

    public:
        // Constructor
        Star(Color &color, int &radius, std::string name);

        // Functions
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &point) override;

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };
}