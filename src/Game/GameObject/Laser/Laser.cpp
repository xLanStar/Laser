#include "Game/GameObject/Laser/Laser.h"

GameObject::Laser::Laser(sf::Vector2f position, Color &color, int thickness, float arc, sf::FloatRect &borderRect, ParticleSystemProp &prop) : GameObject(color, position), borderRect(borderRect), thickness(thickness), arc(arc), particleSystem(prop)
{
}

bool GameObject::Laser::isDestroyed() const //是否該被刪除
{
    return destroyed;
}

void GameObject::Laser::destroy() //改為可刪除
{
    this->destroyed = true;
}

ParticleSystem &GameObject::Laser::getParticleSystem() //取得粒子效果
{
    return particleSystem;
}
