#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Color.h"

namespace GameObject
{
    class GameObject : public sf::Drawable
    {
    private:
        Color &color;
        sf::Vector2f position;

    public:
        // Constructor & Deconstructor
        GameObject(sf::Vector2f position, Color &color);
        GameObject();
        virtual ~GameObject();

        // Accessors
        sf::Vector2f &getPosition();
        Color &getColor();

        // Virtual Functions
        virtual void setPosition(sf::Vector2f &position);
        virtual void setColor(Color &color) = 0;
        virtual void updateMouseMove(sf::Vector2f &point){};
        virtual void updateMousePress(sf::Vector2f &point){};
        virtual void updateMouseRelease(sf::Vector2f &point){};
        virtual void update(float &deltaTime) = 0;
    };
}