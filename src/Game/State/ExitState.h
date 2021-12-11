#pragma once

#include <map>

#include "Game/State/State.h"

class ExitState : public State
{
private:
    // Variables
    sf::Font buttonFont;

    // Initializer
    void initUI();

    // UI Event
    void onYesButtonClick();
    void onNoButtonClick();

public:
    // Constructor
    ExitState(Game &game);
    ~ExitState();

    // Functions
    //void render();
};