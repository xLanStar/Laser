#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Text : public GameObject
    {
    private:
        // Text Appearance
        std::string str;
        sf::Text text;
        sf::Font &font;

        // UI Draw Function
        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    public:
        // Constructor & Deconstructor
        Text(Point position, int &characterSize, sf::Font &font, std::string str);
        ~Text();

        // Accessors
        sf::FloatRect getGlobalBounds();

        // Functions
        void setPosition(Point &position) override;
        void setCharacterSize(int &characterSize);
        void setText(std::string &str);
        void setFont(sf::Font &font);

        // Update Events
        void updateMouseMove(Point &point) override;
        void updateMousePress(Point &point) override;
        void updateMouseRelease(Point &point) override;
        void update() override;
    };
}