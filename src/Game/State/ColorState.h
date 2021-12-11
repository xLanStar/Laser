#pragma once

#include <map>

#include "Game/State/State.h"

class ColorState : public State
{
private:
    // Variables
    sf::Font buttonFont;

    // Initializer
    void initUI();

public:
    // Constructor
    ColorState(Game &game);
    ~ColorState();

    // Functions
    //void render();
};