#pragma once

#include <map>

#include "Game/State/State.h"

class MainMenuState : public State
{
private:
    // Variables
    sf::Font buttonFont;

    // Initializer
    void initUI();

    // UI Event
    void onPlayButtonClick();
    void onSettingButtonClick();

public:
    // Constructor
    MainMenuState(Game &game);
    ~MainMenuState();

    // Functions
    void Quit() override;
    //void render();
};