#pragma once

#include "Game/State/State.h"

class DifficultyState : public State
{
private:
    // Initializer
    void initUI();
public:
    // Constructor
    DifficultyState(Game &game);
};