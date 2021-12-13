#pragma once

#include "Game/Color.h"
#include "Game/GameObject/Text.h"
#include "Game/GameObject/Pantone.h"

namespace GameObject
{
    class ColorTile : public GameObject
    {
    private:
        // Tile Information
        sf::Vector2f &rect;
        Text text;
        Pantone pantone;

        // Tile State
        bool pressed;
        bool hover;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        // Constructor & Deconstructor
        ColorTile(sf::Vector2f position, sf::Vector2f &rect, int &characterSize, sf::Font &font, int &points, int &radius, float &hoverScale, Color &color, std::function<void()> onClick);
        ~ColorTile();

        // Accessors
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &position) override;

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;
        void updateMousePress(sf::Vector2f &point) override;
        void updateMouseRelease(sf::Vector2f &point) override;
        void update(float &deltaTime) override;
    };
}
