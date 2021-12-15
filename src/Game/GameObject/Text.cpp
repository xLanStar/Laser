#include "Game/GameObject/Text.h"

#include <iostream>

// UI Draw Function
void GameObject::Text::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
}

GameObject::Text::Text(sf::Vector2f position, int &characterSize, Color &color, sf::Font &font, std::string str) : GameObject(position, color), font(font)
{
    text.setFont(font);
    setColor(color);
    setText(str);
    setCharacterSize(characterSize);
    setPosition(position);
}

GameObject::Text::~Text()
{
}

// Accessors
sf::FloatRect GameObject::Text::getGlobalBounds()
{
    return text.getGlobalBounds();
}

std::string GameObject::Text::getText()
{
    return text.getString();
}

sf::Font &GameObject::Text::getFont()
{
    return font;
}

// Functions
void GameObject::Text::setColor(Color &color)
{
    text.setFillColor(color.getDarkColor());
}
    
void GameObject::Text::setCharacterSize(int &characterSize)
{
    text.setCharacterSize(characterSize);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
}

void GameObject::Text::setText(std::string &str)
{
    text.setString(str);
}

void GameObject::Text::setPosition(sf::Vector2f &point)
{
    GameObject::setPosition(point);
    text.setPosition(point.x, point.y);
}

// Mouse Move
void GameObject::Text::updateMouseMove(sf::Vector2f &point)
{
}

// Mouse Press
void GameObject::Text::updateMousePress(sf::Vector2f &point)
{
}

// Mouse Release
void GameObject::Text::updateMouseRelease(sf::Vector2f &point)
{
}

void GameObject::Text::update(float &deltaTime)
{
    
}