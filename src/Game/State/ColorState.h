// 選取顏色的狀態
#pragma once

#include "Game/State/State.h"

class ColorState : public State
{
private:
    int borderSize = 300;
    
    // Initializer
    void initUI();

public:
    // Constructor
    ColorState(Game &game);
};