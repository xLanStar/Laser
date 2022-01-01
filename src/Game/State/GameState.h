#pragma once

#include "Game/State/State.h"
#include "Game/GameObject/Laser/Laser.h"
#include "Game/GameObject/Text.h"

class GameState : public State
{
private:
    int borderSize = 80;
    sf::FloatRect borderRect;
    int borderLeft, borderTop, borderRight, borderBottom;
    int randomPositionWidthSize;  // rand() * randomPositionWidthSize + borderLeft
    int randomPositionHeightSize; // rand() * randomPositionHeightSize + borderTop

    float normalLaserGenerateInterval;       //普通雷射的間隔
    float pulseLaserGenerateInterval;        //脈衝雷射的間隔
    float normalLaserCounter = 0;            //普通雷射的計時器
    float pulseLaserCounter = 0;             //脈衝雷射的計時器
    std::vector<GameObject::Laser *> lasers; //雷射容器
    sf::RectangleShape border;
    sf::RectangleShape borderBackground;

    // Initializer
    void initUI();

public:
    // Constructor
    GameState(Game &game);
    ~GameState();

    // Update Functions
    void updateMouseMove(sf::Vector2f &point) override;
    void updateMousePress(sf::Vector2f &point) override;
    void updateMouseRelease(sf::Vector2f &point) override;
    void update(float deltaTime) override;

    // UI Draw Function
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};