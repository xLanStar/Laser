#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Point.h"

namespace GameObject
{
    class GameObject : public sf::Drawable
    {
    private:
        Point position;
    public:
        
        // Constructor & Deconstructor
        GameObject(Point position);
        GameObject();
        virtual ~GameObject();

        // Accessors
        Point &getPosition();

        // Virtual Functions
        virtual void setPosition(Point &position);
        virtual void updateMouseMove(Point &point) = 0;
        virtual void updateMousePress(Point &point)  = 0;
        virtual void updateMouseRelease(Point &point) = 0;
        virtual void update() = 0;
    };
}