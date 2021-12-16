#pragma once

#include "SFML/System/Vector2.hpp"

struct ParticleSystemProp
{
    // ParticleSystem
    bool loop; // whether particle system emit loop

    // Duration
    float duration; // the total duration of particle system

    // Emission
    float rateOverTime; // emit times per second

    // Particle Count
    unsigned int maxParticleCount; // max particle count in time

    // Particle size
    float size;

    // Particle size over time

    // Particle texture
    sf::Texture texture;

    // Particle lifeTime
    bool randomLifeTime;    // whether particle has random lifetime
    float minLifeTimeRange; // 0.0f ~ 1.0f, rand() * (1 - minLifeTimeRange * lifeTime) + minLifeTimeRange * lifeTime
    float lifeTime;         // particle life time

    // Pariticle speed
    float speed; // particle move speed

    // Particle color
    sf::Color color;

    // Particle fade out
    bool fadeout;
};
