#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class NormalLaser : public Laser
    {
    private:
        // Debug
        sf::RectangleShape box;
        sf::RectangleShape box2;

        // Laser Parameter
        int &length;              // laser length
        float angle;              // laser angle
        float &speed;             // movement speed
        sf::Vector2f velocity;    // 1 second move (deltaX, deltaY)
        sf::Vector2f endPosition; // EndPoint At (endX, endY)
        sf::RectangleShape line;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        // Constructor
        NormalLaser(sf::Vector2f position, int &length, int &thickness, float &angle, float &speed, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop);
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