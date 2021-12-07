#include "Game/State/SettingState.h"

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/State/State.h"

// UI Events

void SettingState::onColorButtonClick()
{
    std::cout << "Color Button Click!\n";
}

void SettingState::onPatternButtonClick()
{
    std::cout << "Pattern Button Click!\n";
}


//Initializer
void SettingState::initButtons()
{
    buttons["Color"] = new Gameobject::Button(
        50, 40,
        (std::string) "Color",
        setting,
        [&]{onColorButtonClick();});
    buttons["Pattern"] = new Gameobject::Button(
        50, 60,
        (std::string) "Pattern",
        setting,
        [&]{onPatternButtonClick();});
}

//Constructor
SettingState::SettingState(Setting &setting, std::stack<State *> &states) : State(setting, states)
{
    initButtons();
}

SettingState::~SettingState()
{
    // Clear Buttons
    for(auto it = buttons.begin(); it!=buttons.end(); it++)
    {
        buttons.erase(it);
    }
}

// Functions
// update Events
void SettingState::updateMouseMove(int x, int y)
{
    // check if button is pressed
    for (auto it : buttons)
    {
        it.second->updateMouseMove(x,y);
    }
}

void SettingState::updateMousePress(int x, int y)
{
    // update Buttons
    for (auto it : buttons)
    {
        it.second->updateMousePress(x,y);
    }
}

void SettingState::updateMouseRelease(int x, int y)
{
    // update Buttons
    for (auto it : buttons)
    {
        it.second->updateMouseRelease(x, y);
    }
}


//
void SettingState::update(float deltaTime)
{
    /**
     * - update UI
    **/
    for (auto it : buttons)
    {
        it.second->update();
    }
}

void SettingState::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    /**
     * - draw buttons
     */
    for (auto it : buttons)
    {
        //it.second->render();
        target.draw(*it.second);
    }
}