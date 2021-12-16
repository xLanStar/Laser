#include <cmath>

#include "SFML/Graphics.hpp"

#include "Game/Particle/Particle.h"
#include "Game/Particle/ParticleSystemProp.h"
#include "Game/Util.h"

class ParticleSystem : public sf::Drawable
{
private:
    sf::Vector2f position;

    // particle system statement
    bool active;
    bool emitting;
    unsigned int activeParticleCount;

    // log over time
    float overTime;

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
    ~ParticleSystem();

    // Accessors
    bool &isActive();
    void Emit(sf::Vector2f position);
    void stopEmitting();
    bool &isEmitting();
    bool isAlive();

    // update function
    void update(float deltaTime);
};