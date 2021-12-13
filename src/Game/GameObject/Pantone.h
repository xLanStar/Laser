#pragma once

#include <functional>

#include "SFML/Graphics.hpp"

#include "Game/Color.h"
#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Pantone : public GameObject
    {
    private:
        // Pantone State
        bool pressed;
        bool hover;

        // Pantone Appearance
        int x, y, &points, &radius;
        float &hoverScale;
        Color &color;
        sf::ConvexShape leftConvex, rightConvex;

        // Pantone Click Event
        std::function<void()> onClick;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        // UI Update Function
        void setupShape();
        void setHover(bool isHovered);

    public:
        // Constructor & Deconstructor
        Pantone(sf::Vector2f position, int &points, int &radius, float &hoverScale, Color &color, std::function<void()> onClick);
        ~Pantone();

        // Accessors
        int &getRadius();
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &position) override;

        // Update Functions
        void updateMouseMove(sf::Vector2f &point) override;
        void updateMousePress(sf::Vector2f &point) override;
        void updateMouseRelease(sf::Vector2f &point) override;
        void update(float &deltaTime) override;
    };
};