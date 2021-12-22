#pragma once

#include <map>

#include "Game/State/State.h"

class ColorState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    ColorState(Game &game);

    // Functions
    //void render();
};