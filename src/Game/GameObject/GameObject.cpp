#include "Game/GameObject/GameObject.h"

GameObject::GameObject::GameObject(sf::Vector2f position, Color &color) : position(position), color(color)
{
}
GameObject::GameObject::GameObject() : position(0, 0), color(color)
{
}

GameObject::GameObject::~GameObject()
{
}

sf::Vector2f &GameObject::GameObject::getPosition()
{
    return position;
}

Color &GameObject::GameObject::getColor()
{
    return color;
}

void GameObject::GameObject::setPosition(sf::Vector2f &point)
{
    position.x = point.x;
    position.y = point.y;
}

void GameObject::GameObject::setColor(Color &color)
{
    this->color = color;
}