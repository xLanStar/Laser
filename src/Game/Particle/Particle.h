#include "SFML/Graphics.hpp"

class Particle : public sf::CircleShape //粒子效果
{
private:
public:
    bool active;           //是否存活
    sf::Vector2f velocity; //速度
    float lifeTime;        //生存時間

    Particle(sf::Vector2f velocity, float lifeTime);
    Particle();
};