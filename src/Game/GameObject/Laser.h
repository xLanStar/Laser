#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/GameObject.h"
#include "Game/Game.h"

namespace GameObject
{
    class Laser : public GameObject
    {
    private:
        int &borderSize;
        bool destroyed = false;

    public:
        // Constructor
        Laser(int &borderSize);
        ~Laser();

        // Accessors
        bool &isDestroyed();
        void destroy();
        virtual void setColor(Color &color) = 0;
        virtual void setPosition(sf::Vector2f &point) = 0;
        virtual bool isCollided(sf::Vector2f &point, int &radius) = 0;

        // Update Events
        virtual void updateMouseMove(sf::Vector2f &point) = 0;
        virtual void updateMousePress(sf::Vector2f &point) = 0;
        virtual void updateMouseRelease(sf::Vector2f &point) = 0;
        virtual void update(float &deltaTime) = 0;
    };
};