#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/GameObject.h"
#include "Game/Game.h"

namespace GameObject
{
    class Laser : public GameObject
    {
    private:
        sf::FloatRect &borderRect;
        int &thickness;
        bool destroyed = false;

    public:
        // Constructor
        Laser(sf::Vector2f position, Color &color, int &thickness, sf::FloatRect &borderRect);
        ~Laser();

        // Accessors
        bool &isDestroyed();
        void destroy();
        int &getThickness();
        sf::FloatRect &getBorderRect();
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