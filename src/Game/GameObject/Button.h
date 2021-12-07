#pragma once

#include <functional>

#include <SFML/Graphics.hpp>

#include "Game/Setting.h"
/**
enum button_states
{
    BTN_IDLE,
    BTN_HOVER,
    BTN_ACTIVE
};
**/

namespace Gameobject
{
    class Button : public sf::Drawable
    {
    private:
        // unsigned short buttonState;
        // unsigned short id;

        // Button State
        bool pressed;
        bool hover;

        // Button Appearance
        int x, y;
        Setting &setting;
        std::string str;
        sf::Text text;
        
        // Button event
        std::function<void()> onClick;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        // UI Update Function
        void setHover(bool isHovered);

    public:
        // Constructor
        Button(int x, int y, std::string text, Setting &setting, std::function<void()> onClick);
        ~Button();

        // Accessors

        // Functions
        void updateMouseMove(int x, int y);
        void updateMousePress(int x, int y);
        void updateMouseRelease(int x, int y);
        void update();
    };
};