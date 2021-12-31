#pragma once

#include "Game/State/State.h"

class ProducerState : public State
{
private:
    // Initializer
    void initUI();
public:
    // Constructor
    ProducerState(Game &game);
};