#include "Game/Particle/Particle.h"

Particle::Particle(sf::Vector2f velocity, float lifeTime) : velocity({0.f, 0.f}), lifeTime(0.f), active(false) //設定速度、粒子的生存時間
{
}

Particle::Particle() : active(false)
{
}