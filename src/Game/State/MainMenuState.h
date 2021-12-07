#pragma once

#include <map>

#include "Game/Gameobject/Button.h"
#include "Game/State/State.h"

class MainMenuState : public State
{
private:
    // Variables
    sf::Font buttonFont;

    // UI
    std::map<std::string, Gameobject::Button *> buttons;

    // Initializer
    void initButtons();

    // UI Draw Function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    // UI Event
    void onPlayButtonClick();
    void onSettingButtonClick();

public:
    // Constructor
    MainMenuState(Setting &setting, std::stack<State *> &states);
    ~MainMenuState();

    // Functions
    void Quit();
    void updateMouseMove(int x, int y) override;
    void updateMousePress(int x, int y) override;
    void updateMouseRelease(int x, int y) override;
    void update(float deltaTime) override;
    //void render();
};