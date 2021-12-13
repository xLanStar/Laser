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
        Button(sf::Vector2f position, int &characterSize, int &hoverCharacterSize, Color &color, sf::Font &font, std::string str, std::function<void()> onClick);
        ~Button();

        // Accessors
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &position) override;

        // Update Functions
        void updateMouseMove(sf::Vector2f &point) override;
        void updateMousePress(sf::Vector2f &point) override;
        void updateMouseRelease(sf::Vector2f &point) override;
        void update(float &deltaTime) override;
    };
};