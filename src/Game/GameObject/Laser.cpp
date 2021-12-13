#include "Game/GameObject/Laser.h"

GameObject::Laser::Laser(int &borderSize) : borderSize(borderSize)
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

void GameObject::Laser::update(float &deltaTime)
{
}