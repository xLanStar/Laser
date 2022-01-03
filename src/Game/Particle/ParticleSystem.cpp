#include "Game/Particle/ParticleSystem.h"

#include <cmath>

ParticleSystem::ParticleSystem(ParticleSystemProp &prop) : prop(prop), particles(prop.maxParticleCount), active(false), emitting(true), overTime(0), emitTimeCounter(0), activeParticleCount(0)
{
    // 初始化粒子
    for (Particle &particle : particles)
    {
        particle.setRadius(8);                  //粒子的半徑
        particle.setOrigin(sf::Vector2f(4, 4)); // 設置中心點
        particle.lifeTime = 0;                  //粒子的生存時間
    }
    if (prop.rateOverTime > 0) //單位時間產生的粒子數量
    {
        emitTime = 1 / prop.rateOverTime; // 計算發射間隔時間
    }
    else
    {
        emitTime = 0;
    }
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const // 渲染
{
    if (active) // 如果有效
    {
        // 繪製每一個粒子
        for (auto &particle : particles)
        {
            if (particle.active)
            {
                target.draw(particle);
            }
        }
    }
}

void ParticleSystem::resetParticle(Particle &particle)
{
    // 重置位置
    switch (shape)
    {
    case Dot:
        particle.setPosition(getPosition());
        break;
    case Line:
        float random = static_cast<float>(rand() % 100) / 100; //隨機產生偏移細數
        particle.setPosition(sf::Vector2f(getPosition().x + offset * cos(getRotation()) * random, getPosition().y + offset * sin(getRotation()) * random));
        break;
    }

    float arc = degToArc(std::rand() % 360);                                                  //隨機取得弧度
    particle.velocity = sf::Vector2f(std::cos(arc) * prop.speed, std::sin(arc) * prop.speed); // 取得速度的分量

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

    particle.setFillColor(prop.color);
}

bool ParticleSystem::isActive() // 粒子系統是否啟用
{
    return active;
}

void ParticleSystem::Emit() // 粒子系統啟動發射
{
    emitting = true;
    active = true;
}

void ParticleSystem::stopEmitting() // 粒子系統停止發射 (但活著的粒子並不會立即消失)
{
    emitting = false;
}

bool ParticleSystem::isEmitting() // 粒子系統是否正在發射
{
    return emitting;
}

bool ParticleSystem::isAlive() // 粒子系統是否還有粒子存活
{
    return emitting || activeParticleCount != 0;
}

void ParticleSystem::setShape(ParticleSystemShape shape, float offset) // 取得現在使用怎麼樣的形式
{
    this->shape = shape;   // 使用的模式
    this->offset = offset; // 偏移量
}

void ParticleSystem::update(float deltaTime) // 更新
{
    if (active) // 如果還有活著的粒子
    {
        overTime += deltaTime;        // 總經過的時間計時器
        emitTimeCounter += deltaTime; // 發射計時器
        for (auto particle = particles.begin(); particle != particles.end();)
        {
            if (particle->lifeTime <= 0) // 如果粒子死了
            {
                if (emitting) // 如果正在發射
                {
                    if (emitTimeCounter >= emitTime) // 如果粒子超過應有的發射時間
                    {
                        emitTimeCounter -= emitTime;
                        resetParticle(*particle); //重設粒子
                        particle->active = true;  //啟用例子
                        activeParticleCount++;    //已啟用的粒子數量+1
                    }
                }
                else if (particle->active) //如果粒子已啟用
                {
                    particles.erase(particle); //刪除粒子
                    activeParticleCount--;     //已啟用的粒子數量-1
                    continue;
                }
            }
            else if (particle->active) //如果粒子已啟用
            {
                particle->lifeTime -= deltaTime; //粒子的生命計時器

                particle->move(particle->velocity * deltaTime); //粒子移動

                if (prop.fadeout) //如果粒子啟用漸出特效
                {
                    float ratio = particle->lifeTime / prop.lifeTime; //生命週期百分比
                    sf::Color color = particle->getFillColor();       //取得顏色
                    if (ratio <= 0)
                    {
                        color.a = 0;
                    }
                    else
                    {
                        color.a = static_cast<sf::Uint8>(ratio * 255);
                    }
                    particle->setFillColor(color); //設定顏色
                }
            }
            particle++;
        }
        if (emitting && (!prop.loop && overTime >= prop.duration)) //如果正在發射並且已經持續超過設定的時間
        {
            stopEmitting(); //停止發射
        }
    }
}