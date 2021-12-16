#include "Game/Particle/Particle.h"

Particle::Particle(sf::Vector2f velocity, float lifeTime) : velocity({0.f,0.f}), lifeTime(0.f), active(false)
{
}

Particle::Particle() : active(false)
{
}

Particle::~Particle()
{
}