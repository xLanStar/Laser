#pragma once

#include "Game/Setting.h"
#include "Game/GameObject/Tile.h"

namespace GameObject
{
    class PatternTile : public Tile
    {
    private:
    
        // Tile State
        bool pressed;
        bool hover;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        // Constructor & Deconstructor
        PatternTile(Point position);
        ~PatternTile();

        // Update Events
        void setPosition(Point &position) override;
        void updateMouseMove(Point &point) override;
        void updateMousePress(Point &point) override;
        void updateMouseRelease(Point &point) override;
        void update() override;
    };
}
