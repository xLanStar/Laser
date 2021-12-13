#include "Game/GameObject/GameObject.h"

GameObject::GameObject::GameObject(sf::Vector2f position) : position(position)
{
}
GameObject::GameObject::GameObject() : position(0, 0)
{
}

GameObject::GameObject::~GameObject()
{
}

sf::Vector2f &GameObject::GameObject::getPosition()
{
    return position;
}

void GameObject::GameObject::setPosition(sf::Vector2f &point)
{
    position.x = point.x;
    position.y = point.y;
}