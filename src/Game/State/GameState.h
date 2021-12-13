#pragma once

#include <vector>

#include "Game/State/State.h"
#include "Game/GameObject/Laser.h"

class GameState : public State
{
private:
    float &generateInterval;
    float counter = 0;
    std::vector<GameObject::Laser *> lasers;
    GameObject::Text mvpText, scoreText;
    sf::RectangleShape border;

    // Initializer
    void initUI();

    // Private Functions
    void death();
public:
    // Constructor
    GameState(Game &game);
    ~GameState();

    // Update Functions
    void updateMouseMove(sf::Vector2f &point) override;
    void updateMousePress(sf::Vector2f &point) override;
    void updateMouseRelease(sf::Vector2f &point) override;
    void update(float &deltaTime) override;
    
    // UI Draw Function
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};