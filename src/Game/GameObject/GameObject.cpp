#include "Game/GameObject/GameObject.h"

GameObject::GameObject::GameObject(Color &color, sf::Vector2f position) : color(color), position(position)
{
}

sf::Vector2f GameObject::GameObject::getPosition() const
{
    return position;
}

void GameObject::GameObject::setColor(Color &color)
{
    color = color;
}

void GameObject::GameObject::setPosition(sf::Vector2f point)
{
    position = point;
}
