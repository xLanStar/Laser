#pragma once

#include <map>

#include "Game/State/State.h"

class ReplayState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    ReplayState(Game &game);
    ~ReplayState();
};