#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Color.h"
#include "Game/GameObject/Text.h"

namespace GameObject
{
    class Pattern : public GameObject
    {
    private:
        // Pattern Appearance
        Color &color;
        int &radius;
        sf::CircleShape circle;

        // Pricate Function
        void setupShape();

    public:
        // Constructor
        Pattern(Color &color, int &radius, std::string name);
        ~Pattern();

        // Accessors
        int &getRadius();
        Color &getColor();
        virtual void setColor(Color &color);
        virtual void setPosition(sf::Vector2f &point);

        // Update Events
        virtual void updateMouseMove(sf::Vector2f &point);
        virtual void updateMousePress(sf::Vector2f &point);
        virtual void updateMouseRelease(sf::Vector2f &point);
        virtual void update(float &deltaTime);
        
        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };
};