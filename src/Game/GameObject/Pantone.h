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
        // unsigned short PantoneState;
        // unsigned short id;

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
        Pantone(Point position, int &points, int &radius, float &hoverScale, Color &color, std::function<void()> onClick);
        ~Pantone();

        // Accessors
        int &getRadius();

        // Functions
        void setPosition(Point &position) override;
        // void setPoints(int &points);
        // void setRadius(int &radius);
        // void setHoverScale(float &hoverScale);
        // void setColor(Color &color);

        // Update Functions
        void updateMouseMove(Point &point) override;
        void updateMousePress(Point &point) override;
        void updateMouseRelease(Point &point) override;
        void update() override;
    };
};