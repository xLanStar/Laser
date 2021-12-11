#pragma once

#include <functional>

#include "SFML/Graphics.hpp"

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Pattern : public GameObject
    {
    private:
        // unsigned short PatternState;
        // unsigned short id;

        // Pattern Appearance
        int x, y;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        // UI Update Function
        void setupShape();

    public:
        // Constructor
        Pattern(Point position);
        Pattern();
        ~Pattern();

        // Functions
        void setPosition(Point &position) override;
        void updateMouseMove(Point &point) override;
        void updateMousePress(Point &point) override;
        void updateMouseRelease(Point &point) override;
        void update() override;
    };
};