#pragma once

#include <map>

#include "Game/State/State.h"

class SettingState : public State
{
private:
    // Initializer
    void initUI();

    // UI Event
    void onPatternButtonClick();
    void onColorButtonClick();

public:
    // Constructor
    SettingState(Game &game);
    ~SettingState();

    // Functions
    //void render();
};