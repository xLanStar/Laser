#include "Game/Particle/ParticleSystem.h"

#include <iostream>

ParticleSystem::ParticleSystem(ParticleSystemProp &prop) : prop(prop), particles(prop.maxParticleCount), active(false), emitting(true), overTime(0), emitTimeCounter(0), activeParticleCount(0)
{
    for (Particle &particle : particles)
    {
        particle.setTexture(prop.texture);
        particle.setOrigin(sf::Vector2f(particle.getTextureRect().width / 2, particle.getTextureRect().height / 2));
    }
    emitTime = 1 / prop.rateOverTime;
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (active)
    {
        for (auto &particle : particles)
        {
            if(particle.active)
            {
                target.draw(particle);
            }
        }
    }
}

void ParticleSystem::resetParticle(Particle &particle)
{
    // reset the position of particle
    particle.setPosition(position);

    // give a random velocity and lifetime to the particle
    float angle = (std::rand() % 360) * PI / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    particle.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

    // set lifeTime of particle
    if (prop.randomLifeTime)
    {
        static int randomRange = 1000 * prop.lifeTime * (1.0f - prop.minLifeTimeRange);
        static float minLifeTime = prop.lifeTime * prop.minLifeTimeRange;
        particle.lifeTime = (std::rand() % randomRange) / 1000.0f + minLifeTime;
    }
    else
    {
        particle.lifeTime = prop.lifeTime;
    }

    // reset the color of particle
    particle.setColor(prop.color);
}

bool &ParticleSystem::isActive()
{
    return active;
}

void ParticleSystem::Emit(sf::Vector2f position)
{
    std::cout << "[ParticleSystem] Activate\n";

    this->position = position;

    emitting = true;
    active = true;
}

void ParticleSystem::stopEmitting()
{
    emitting = false;
}

bool &ParticleSystem::isEmitting()
{
    return emitting;
}

bool ParticleSystem::isAlive()
{
    return activeParticleCount != 0;
}

void ParticleSystem::update(float deltaTime)
{
    if (active)
    {
        overTime += deltaTime;
        emitTimeCounter += deltaTime;
        if (emitting && !prop.loop && overTime > prop.duration)
        {
            emitting = false;
        }
        for (auto particle = particles.begin(); particle != particles.end();)
        {
            // if the particle is dead, and system is not out of duration respawn it
            if (particle->lifeTime <= 0)
            {
                if (emitting)
                {
                    if(emitTimeCounter >= emitTime)
                    {
                        emitTimeCounter -= emitTime;
                        resetParticle(*particle);
                        particle->active = true;
                        activeParticleCount++;
                    }
                }
                else if(particle->active)
                {
                    particles.erase(particle);
                    activeParticleCount--;
                    continue;
                }
            }
            else if(particle->active)
            {
                particle->lifeTime -= deltaTime;

                // update the position of the corresponding vertex
                particle->move(particle->velocity * deltaTime);
                //std::cout << "[ParticleSystem] " << particle->getPosition().x << ", " << particle->getPosition().y << '\n';

                // update the alpha (transparency) of the particle according to its lifetime
                if (prop.fadeout)
                {
                    float ratio = particle->lifeTime / prop.lifeTime;
                    sf::Color color = particle->getColor();
                    if (ratio <= 0)
                    {
                        color.a = 0;
                    }
                    else
                    {
                        color.a = static_cast<sf::Uint8>(ratio * 255);
                    }
                    particle->setColor(color);
                }
            }
            particle++;
        }
    }
}