// 選取顏色的狀態
#pragma once

#include "Game/State/State.h"

class ColorState : public State
{
private:
    // Initializer
    void initUI();

public:
    // Constructor
    ColorState(Game &game);
};