#pragma once

#include <map>

#include "Game/State/State.h"

class PatternState : public State
{
private:
    // Variables
    sf::Font buttonFont;

    // Initializer
    void initUI();

public:
    // Constructor
    PatternState(Game &game);
    ~PatternState();

    // Functions
    //void render();
};