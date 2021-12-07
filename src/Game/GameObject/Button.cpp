#include "Button.h"

#include <iostream>

#include "SFML/Graphics.hpp"

// UI Draw Function
void Gameobject::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->text, states);
}

// Constructor
Gameobject::Button::Button(int x, int y, std::string text, Setting &setting, std::function<void()> onClick) : setting(setting)
{
    this->x = x;
    this->y = y;
    this->str = text;
    this->onClick = onClick;
    // this->idleColor = idleColor;
    // this->hoverColor = hoverColor;
    // this->activeColor = activeColor;

    // Button State
    pressed = false;

    // Text
    this->text.setFont(setting.getFont());
    this->text.setCharacterSize(24);
    this->text.setString(text);

    setHover(false);
}

Gameobject::Button::~Button()
{
}

void Gameobject::Button::setHover(bool isHovered)
{
    hover = isHovered;
    if (hover)
    {
        this->text.setCharacterSize(setting.getHoverCharacterSize());
    }
    else
    {
        this->text.setCharacterSize(setting.getCharacterSize());
    }
    // Update Text Position
    sf::FloatRect textRect = this->text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(x * setting.getScreenWidth() / 100, y * setting.getScreenHeight() / 100);
}

// Mouse Move
void Gameobject::Button::updateMouseMove(int x, int y)
{
    sf::FloatRect rect = text.getGlobalBounds();
    if (rect.top <= y && y <= rect.top + rect.height && rect.left <= x && x <= rect.left + rect.width)
    {
        if (!hover)
        {
            setHover(true);
            std::cout << "[Button] " << str << " Hover In!\n";
        }
    }
    else
    {
        if (hover)
        {
            setHover(false);
            std::cout << "[Button] " << str << " Hover Out!\n";
        }
    }
}

// Mouse Press
void Gameobject::Button::updateMousePress(int x, int y)
{
    if (hover && !pressed)
    {
        pressed = true;
        std::cout << "[Button] " << str << " Mouse Press!\n";
    }
}

// Mouse Release
void Gameobject::Button::updateMouseRelease(int x, int y)
{
    if (pressed)
    {
        sf::FloatRect rect = text.getGlobalBounds();
        if (hover)
        {
            onClick();
            std::cout << "[Button] " << str << " Triggered!\n";
        }
        std::cout << "[Button] " << str << " Released!\n";
    }
}

void Gameobject::Button::update()
{
}