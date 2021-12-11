#pragma once

#include <functional>

#include <SFML/Graphics.hpp>

#include "Game/Setting.h"
#include "Game/GameObject/GameObject.h"
#include "Game/GameObject/Text.h"
/**
enum button_states
{
    BTN_IDLE,
    BTN_HOVER,
    BTN_ACTIVE
};
**/

namespace GameObject
{
    class Button : public GameObject
    {
    private:
        // unsigned short buttonState;
        // unsigned short id;

        // Button State
        bool pressed;
        bool hover;

        // Button Appearance
        Text text;
        int &characterSize, &hoverCharacterSize;
        
        // Button event
        std::function<void()> onClick;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        // UI Update Function
        void setHover(bool isHovered);

    public:
        // Constructor
        Button(Point position, int &characterSize, int &hoverCharacterSize, sf::Font &font, std::string str, std::function<void()> onClick);
        ~Button();

        // Functions
        void setPosition(Point &point) override;
        void updateMouseMove(Point &point) override;
        void updateMousePress(Point &point) override;
        void updateMouseRelease(Point &point) override;
        void update() override;
    };
};