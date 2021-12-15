#include "Game/GameObject/Laser.h"

GameObject::Laser::Laser(sf::Vector2f position, Color &color, int &thickness, sf::FloatRect &borderRect) : GameObject(position,color), borderRect(borderRect), thickness(thickness)
{
}

GameObject::Laser::~Laser()
{
}

bool &GameObject::Laser::isDestroyed()
{
    return destroyed;
}

void GameObject::Laser::destroy()
{
    this->destroyed = true;
}

int &GameObject::Laser::getThickness()
{
    return thickness;
}

sf::FloatRect &GameObject::Laser::getBorderRect()
{
    return borderRect;
}

void GameObject::Laser::update(float &deltaTime)
{
}