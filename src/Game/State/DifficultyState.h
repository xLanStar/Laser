#pragma once

#include <map>

#include "Game/State/State.h"

class DifficultyState : public State
{
private:
    // Initializer
    void initUI();
public:
    // Constructor
    DifficultyState(Game &game);
    ~DifficultyState();
};