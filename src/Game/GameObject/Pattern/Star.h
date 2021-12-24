#pragma once

#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{
    class Star : public Pattern
    {
    public:
        // Constructor
        Star(Color &color, int &radius, std::string name);

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