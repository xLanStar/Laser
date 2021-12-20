#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/GameObject.h"
#include "Game/Color.h"

namespace GameObject
{
    class Text : public GameObject
    {
    private:
        // Text Appearance
        sf::Font &font;
        sf::Text text;

        // UI Draw Function
        void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        // Constructor & Deconstructor
        Text(sf::Vector2f position, int &characterSize, Color &color, sf::Font &font, std::string str);
        ~Text();

        // Accessors
        sf::FloatRect getGlobalBounds();
        std::string getText();
        sf::Font &getFont();
        void setColor(Color &color) override;
        void setPosition(sf::Vector2f &position) override;
        void setCharacterSize(int &characterSize);
        void setText(std::string &str);
        void setFont(sf::Font &font);

        // Update Events
        void updateMouseMove(sf::Vector2f &point) override;
        void updateMousePress(sf::Vector2f &point) override;
        void updateMouseRelease(sf::Vector2f &point) override;
        void update(float &deltaTime) override;
    };
}