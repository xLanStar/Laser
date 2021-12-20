#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class PulseLaser : public Laser
    {
    private:
        // Laser Parameter
        int &thickness;      // laser thickness
        float angle;         // laser angle
        float &delay;        // delay time before laser pulse
        float &powerTime;
        float &duration;     // duration time during laser pulsing
        int &dashLineLength; // length of dash line
        sf::Vector2f deltaShake;

        sf::RectangleShape line;

        sf::RectangleShape box;

        bool pulsing = false;
        float counter = 0.f;
        float liveTime;
        float deltaThickness;

        std::vector<sf::RectangleShape> dashLine;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        // Constructor
        PulseLaser(sf::Vector2f position, int &thickness, float &angle, float &delay, float &powerTime, float &duration, int &dashLineLength, int &dashLineThickness, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop);
        ~PulseLaser();

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