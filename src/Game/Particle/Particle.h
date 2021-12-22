#include "SFML/Graphics.hpp"

class Particle : public sf::Sprite
{
private:
public:
    bool active;
    sf::Vector2f velocity;
    float lifeTime;

    // Constructor
    Particle(sf::Vector2f velocity, float lifeTime);
    Particle();
};