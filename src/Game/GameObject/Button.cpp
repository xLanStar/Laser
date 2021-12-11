#include "Button.h"

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Game/Game.h"

// UI Draw Function
void GameObject::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
}

// Constructor
GameObject::Button::Button(Point position, int &characterSize, int &hoverCharacterSize, sf::Font &font, std::string str, std::function<void()> onClick) : GameObject(position), onClick(onClick), pressed(false), text(position, characterSize, font, str), characterSize(characterSize), hoverCharacterSize(hoverCharacterSize)
{
}

GameObject::Button::~Button()
{
}

void GameObject::Button::setHover(bool isHovered)
{
    hover = isHovered;
    if (hover)
    {
        text.setCharacterSize(hoverCharacterSize);
    }
    else
    {
        text.setCharacterSize(characterSize);
    }
}

void GameObject::Button::setPosition(Point &point)
{
    GameObject::setPosition(point);
    text.setPosition(point);
}

// Mouse Move
void GameObject::Button::updateMouseMove(Point &point)
{
    sf::FloatRect rect = text.getGlobalBounds();
    if (rect.contains(point.x, point.y) && rect.contains(point.x, point.y))
    {
        if (!hover)
        {
            setHover(true);
            // std::cout << "[Button] " << str << " Hover In!\n";
        }
    }
    else
    {
        if (hover)
        {
            setHover(false);
            // std::cout << "[Button] " << str << " Hover Out!\n";
        }
    }
}

// Mouse Press
void GameObject::Button::updateMousePress(Point &point)
{
    if (hover && !pressed)
    {
        pressed = true;
        // std::cout << "[Button] " << str << " Mouse Press!\n";
    }
}

// Mouse Release
void GameObject::Button::updateMouseRelease(Point &point)
{
    if (pressed)
    {
        pressed = false;
        if (hover)
        {
            onClick();
            // std::cout << "[Button] " << str << " Triggered!\n";
        }
        // std::cout << "[Button] " << str << " Released!\n";
    }
}

void GameObject::Button::update()
{
}