#pragma once

#include <map>

#include "Game/State/State.h"

enum PlayStateType
{
    GAME = 0, 
    DIFFICULTY,
    REPLAY
};

class PlayState : public State
{
private:
    // Variables
    State *state;

    // Initializer
    void initUI();

    // UI Draw Function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
    // Constructor
    PlayState(Game &game);

    // Functions
    void switchState(PlayStateType playStateType);

    // Update Functions
    void updateMouseMove(sf::Vector2f &point) override;
    void updateMousePress(sf::Vector2f &point) override;
    void updateMouseRelease(sf::Vector2f &point) override;
    void update(float &deltaTime) override;
};