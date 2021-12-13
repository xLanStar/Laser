#pragma once

#include "Game/GameObject/Pattern.h"

namespace GameObject
{

    class Round : public Pattern
    {
    private:
        // Round Pattern Appearance
        sf::CircleShape circle;

        // Pricate Function
        void setupShape();
    public:
        // Constructor
        Round(Color &color, int &radius, std::string name);
        ~Round();

        // Functions
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &point) override;

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;
        void updateMousePress(sf::Vector2f &point) override;
        void updateMouseRelease(sf::Vector2f &point) override;
        void update() override;
        
        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };
}