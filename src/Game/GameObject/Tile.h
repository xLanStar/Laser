#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Tile : public GameObject
    {
    private:

    public:
        // Constructor & Deconstructor
        Tile(Point position);
        ~Tile();

        // Functions
        virtual void setPosition(Point &point) = 0;

        // Update Events
        virtual void updateMouseMove(Point &point) = 0;
        virtual void updateMousePress(Point &point) = 0;
        virtual void updateMouseRelease(Point &point) = 0;
        virtual void update() = 0;
    };
}