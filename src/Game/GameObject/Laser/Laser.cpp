#include "Game/GameObject/Laser/Laser.h"

GameObject::Laser::Laser(sf::Vector2f position, Color &color, int thickness, float angle, sf::FloatRect &borderRect, ParticleSystemProp &prop) : GameObject(position, color), borderRect(borderRect), thickness(thickness), angle(angle), particleSystem(prop)
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

int GameObject::Laser::getThickness() const //取得寬度
{
    return thickness;
}
float GameObject::Laser::getAngle() const
{
    return angle;
}
sf::FloatRect &GameObject::Laser::getBorderRect() const //取得邊界
{
    return borderRect;
}

ParticleSystem &GameObject::Laser::getParticleSystem() //取得粒子效果
{
    return particleSystem;
}
