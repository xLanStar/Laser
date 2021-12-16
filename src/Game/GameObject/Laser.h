#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Game.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Particle/ParticleSystem.h"
#include "Game/Particle/ParticleSystemProp.h"

namespace GameObject
{
    class Laser : public GameObject
    {
    private:
        sf::FloatRect &borderRect;
        int &thickness;
        bool destroyed = false;

        // Particle System
        ParticleSystem particleSystem;
    public:
        // Constructor
        Laser(sf::Vector2f position, Color &color, int &thickness, sf::FloatRect &borderRect, ParticleSystemProp &prop);
        ~Laser();

        // Accessors
        bool &isDestroyed();
        void destroy();
        int &getThickness();
        sf::FloatRect &getBorderRect();
        ParticleSystem &getParticleSystem();
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