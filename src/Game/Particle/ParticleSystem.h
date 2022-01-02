#include "Game/Particle/Particle.h"
#include "Game/Particle/ParticleSystemProp.h"
#include "Game/Util.h"

enum ParticleSystemShape
{
    Dot,
    Line
};

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
private:
    sf::Vector2f position;

    // particle system statement
    bool active;
    bool emitting;
    unsigned int activeParticleCount;

    // log over time
    float overTime;

    // Shape
    ParticleSystemShape shape; // Shape
    float length;              // Line

    // Emission
    float emitTimeCounter;
    float emitTime;

    // store all particle
    std::vector<Particle> particles;

    // store the particle system values
    ParticleSystemProp &prop;

    void resetParticle(Particle &particle);

    // ParticleSystem Draw Funcion
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    // constructor
    ParticleSystem(ParticleSystemProp &prop);

    // Accessors
    bool &isActive();
    void Emit();
    void stopEmitting();
    bool &isEmitting();
    bool isAlive();

    // Functions
    void setShape(ParticleSystemShape shape, float length = 0.f); // 粒子系統本身的形狀，相當於粒子應該在哪些範圍內產生

    // update function
    void update(float deltaTime);
};