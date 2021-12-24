#pragma once

#include "Game/State/State.h"

class MainMenuState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    MainMenuState(Game &game);

    // Functions
    void Quit() override;
    //void render();
};