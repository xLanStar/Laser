#pragma once

#include "Game/State/State.h"

class PatternState : public State
{
private:
    int borderSize = 300;

    int tileGap = 25;     //磁磚容器之間的距離
    // Initializer
    void initUI();

public:
    // Constructor
    PatternState(Game &game);

    // Functions
    //void render();
};