#include "Game/GameObject/GameObject.h"

GameObject::GameObject::GameObject(sf::Vector2f position, Color &color) : position(position), color(color)
{
}

GameObject::GameObject::GameObject() : position(0, 0), color(color)
{
}

sf::Vector2f &GameObject::GameObject::getPosition()
{
    return position;
}

void GameObject::GameObject::setColor(Color &color)
{
    color = color;
}
void GameObject::GameObject::setPosition(sf::Vector2f &position)
{
}