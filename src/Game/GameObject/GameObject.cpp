#include "Game/GameObject/GameObject.h"

GameObject::GameObject::GameObject(Point position) : position(position)
{
}
GameObject::GameObject::GameObject() : position(0, 0)
{
}

GameObject::GameObject::~GameObject()
{
}

Point &GameObject::GameObject::getPosition()
{
    return position;
}

void GameObject::GameObject::setPosition(Point &point)
{
    position.x = point.x;
    position.y = point.y;
}