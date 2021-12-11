#pragma once

#include "Game/Color.h"
#include "Game/GameObject/Tile.h"
#include "Game/GameObject/Text.h"
#include "Game/GameObject/Pantone.h"

namespace GameObject
{
    class ColorTile : public Tile
    {
    private:
        // Tile Information
        int width, height;
        Text text;
        Pantone pantone;

        // Tile State
        bool pressed;
        bool hover;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        // Constructor & Deconstructor
        ColorTile(Point position, int &width, int &height, int &characterSize, sf::Font &font, int &points, int &radius, float &hoverScale, Color &color, std::function<void()> onClick);
        ~ColorTile();

        // Update Events
        void setPosition(Point &position) override;
        void updateMouseMove(Point &point) override;
        void updateMousePress(Point &point) override;
        void updateMouseRelease(Point &point) override;
        void update() override;
    };
}
