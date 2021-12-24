#pragma once

#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{

    class Round : public Pattern
    {
    public:
        // Constructor
        Round(Color &color, int &radius, std::string name);

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