#include "Game/State/ExitState.h"

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/State/State.h"
#include "Game/State/SettingState.h"

// UI Events

void ExitState::onYesButtonClick()
{
    std::cout << "Yes Button Click!\n";

}

void ExitState::onNoButtonClick()
{
    std::cout << "No Button Click!\n";
    Quit();
}


//Initializer
void ExitState::initButtons()
{
    buttons["Yes"] = new Gameobject::Button(
        40, 60,
        (std::string) "YES",
        setting,
        [&]{onYesButtonClick();});
    buttons["No"] = new Gameobject::Button(
        60, 60,
        (std::string) "NO",
        setting,
        [&]{onNoButtonClick();});
}

//Constructor
ExitState::ExitState(Setting &setting, std::stack<State *> &states) : State(setting, states)
{
    initButtons();
}

ExitState::~ExitState()
{
    // Clear Buttons
    for(auto it = buttons.begin(); it!=buttons.end(); it++)
    {
        buttons.erase(it);
    }
}

// Functions
// update Events
void ExitState::updateMouseMove(int x, int y)
{
    // check if button is pressed
    for (auto it : buttons)
    {
        it.second->updateMouseMove(x,y);
    }
}

void ExitState::updateMousePress(int x, int y)
{
    // update Buttons
    for (auto it : buttons)
    {
        it.second->updateMousePress(x,y);
    }
}

void ExitState::updateMouseRelease(int x, int y)
{
    // update Buttons
    for (auto it : buttons)
    {
        it.second->updateMouseRelease(x, y);
    }
}


//
void ExitState::update(float deltaTime)
{
    /**
     * - update UI
    **/
    for (auto it : buttons)
    {
        it.second->update();
    }
}

void ExitState::draw(sf::RenderTarget &target, sf::RenderStates states) const
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