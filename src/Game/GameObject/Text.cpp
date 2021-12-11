#include "Game/GameObject/Text.h"

#include <iostream>

// UI Draw Function
void GameObject::Text::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
}

GameObject::Text::Text(Point position, int &characterSize, sf::Font &font, std::string str) : GameObject(position), font(font)
{
    text.setFont(font);
    setText(str);
    setCharacterSize(characterSize);
    setPosition(getPosition());
}

GameObject::Text::~Text()
{
}

sf::FloatRect GameObject::Text::getGlobalBounds()
{
    return text.getGlobalBounds();
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
    this->str = str;
    text.setString(str);
}

void GameObject::Text::setPosition(Point &point)
{
    GameObject::setPosition(point);
    text.setPosition(point.x, point.y);
}

// Mouse Move
void GameObject::Text::updateMouseMove(Point &point)
{
}

// Mouse Press
void GameObject::Text::updateMousePress(Point &point)
{
}

// Mouse Release
void GameObject::Text::updateMouseRelease(Point &point)
{
}

void GameObject::Text::update()
{
}