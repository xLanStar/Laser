#include "Game/Particle/ParticleSystem.h"

#include <cmath>

ParticleSystem::ParticleSystem(ParticleSystemProp &prop) : prop(prop), particles(prop.maxParticleCount), active(false), emitting(true), overTime(0), emitTimeCounter(0), activeParticleCount(0)
{
    // 初始化粒子
    for (Particle &particle : particles)
    {
        particle.setTexture(prop.texture); // 設置貼圖
        particle.setOrigin(sf::Vector2f(particle.getTextureRect().width / 2, particle.getTextureRect().height / 2)); // 設置中心點
    }
    emitTime = 1 / prop.rateOverTime; // 計算發射間隔時間
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (active)
    {
        // 繪製每一個粒子
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
    // 重置位置
    particle.setPosition(position);

    // 隨機角度與速度
    float angle = (std::rand() % 360) * PI / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    particle.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

    // 設置粒子的生命週期
    if (prop.randomLifeTime)
    {
        // 隨機
        static int randomRange = 1000 * prop.lifeTime * (1.0f - prop.minLifeTimeRange);
        static float minLifeTime = prop.lifeTime * prop.minLifeTimeRange;
        particle.lifeTime = (std::rand() % randomRange) / 1000.0f + minLifeTime;
    }
    else
    {
        // 固定
        particle.lifeTime = prop.lifeTime;
    }

    // 重置粒子的顏色
    particle.setColor(prop.color);
}

bool &ParticleSystem::isActive() // 粒子系統是否啟用
{
    return active;
}

void ParticleSystem::Emit(sf::Vector2f position) // 粒子系統啟動發射
{
    this->position = position;

    emitting = true;
    active = true;
}

void ParticleSystem::stopEmitting() // 粒子系統停止發射 (但活著的粒子並不會立即消失)
{
    emitting = false;
}

bool &ParticleSystem::isEmitting() // 粒子系統是否正在發射
{
    return emitting;
}

bool ParticleSystem::isAlive() // 粒子系統是否還有粒子存活
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