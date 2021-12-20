#pragma once

#include <map>

#include "Game/State/State.h"

class MainMenuState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    MainMenuState(Game &game);
    ~MainMenuState();

    // Functions
    void Quit() override;
    //void render();
};