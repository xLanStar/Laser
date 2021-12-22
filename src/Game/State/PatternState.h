#pragma once

#include <map>

#include "Game/State/State.h"

class PatternState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    PatternState(Game &game);

    // Functions
    //void render();
};