#pragma once

struct ParticleSystemProp //粒子系統的屬性
{
    // ParticleSystem
    bool loop; // whether particle system emit loop

    float duration; // 粒子效果的持續時間

    float rateOverTime; // 單位時間的粒子釋放量

    unsigned int maxParticleCount; // 粒子數量

    float size; //粒子大小

    bool randomLifeTime;    // 隨機的產生生存時間
    float minLifeTimeRange; // 0.0f ~ 1.0f, rand() * (1 - minLifeTimeRange * lifeTime) + minLifeTimeRange * lifeTime
    float lifeTime;         // 粒子的時間

    float speed; // 粒子的移動速度

    sf::Color color; //粒子的顏色

    bool fadeout; //粒子是否該消失
};
