#include "Game/Particle/Particle.h"
#include "Game/Particle/ParticleSystemProp.h"
#include "Game/Util.h"

enum ParticleSystemShape //兩種不同的粒子效果
{
    Dot,
    Line
};

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
private:
    sf::Vector2f position; //位置

    bool active;                      //是否仍有粒子存活
    bool emitting;                    //是否正在產生粒子
    unsigned int activeParticleCount; //

    float overTime; //經過的時間

    // Shape
    ParticleSystemShape shape; // Shape
    float offset;              // Line

    // Emission
    float emitTimeCounter;
    float emitTime;

    std::vector<Particle> particles; // 粒子容器

    // store the particle system values
    ParticleSystemProp &prop;

    void resetParticle(Particle &particle);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; // 渲染

public:
    ParticleSystem(ParticleSystemProp &prop);

    bool isActive();
    void Emit();
    void stopEmitting(); // 停止發射
    bool isEmitting();   // 是否正在發射
    bool isAlive();      // 是否還有粒子存活

    void setShape(ParticleSystemShape shape, float length = 0.f); // 粒子系統本身的形狀，相當於粒子應該在哪些範圍內產生

    void update(float deltaTime); // 更新
};