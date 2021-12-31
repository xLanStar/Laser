#pragma once

#include "Game/State/State.h"

class ExitState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    ExitState(Game &game);
};