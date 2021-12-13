#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/Laser.h"

namespace GameObject
{
    class NormalLaser : public Laser
    {
    private:
        // Debug
        sf::RectangleShape box;
        sf::RectangleShape box2;

        // Appearance
        sf::Vector2f &rect;
        int &borderSize;
        float &length;
        float angle, &velocity;
        float deltaX, deltaY;
        float endX, endY;
        sf::RectangleShape line;

        sf::Vector2f &windowRect;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    public:
        // Constructor
        NormalLaser(sf::Vector2f position, sf::Vector2f &rect, float &angle, float &velocity, Color &color, int &borderSize, sf::Vector2f &windowRect);
        ~NormalLaser();

        // Accessors
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &point) override;
        bool isCollided(sf::Vector2f &point, int &radius) override;

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;
        void updateMousePress(sf::Vector2f &point) override;
        void updateMouseRelease(sf::Vector2f &point) override;
        void update(float &deltaTime) override;
    };
};