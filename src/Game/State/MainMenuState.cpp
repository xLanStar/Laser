#include "Game/State/MainMenuState.h"

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"

#include "Game/Gameobject/Button.h"
#include "Game/State/State.h"
#include "Game/State/SettingState.h"
#include "Game/State/ExitState.h"

// UI Events

void MainMenuState::onPlayButtonClick()
{
    std::cout << "Play Button Click!\n";
}

void MainMenuState::onSettingButtonClick()
{
    std::cout << "Setting Button Click!\n";
    states.push(new SettingState(setting, states));
}


//Initializer
void MainMenuState::initButtons()
{
    buttons["Play"] = new Gameobject::Button(
        50, 50,
        (std::string) "PLAY",
        setting,
        [&]{onPlayButtonClick();});
    buttons["Setting"] = new Gameobject::Button(
        50, 70,
        (std::string) "SETTING",
        setting,
        [&]{onSettingButtonClick();});
}

//Constructor
MainMenuState::MainMenuState(Setting &setting, std::stack<State *> &states) : State(setting, states)
{
    initButtons();
}

MainMenuState::~MainMenuState()
{
    // Clear Buttons
    for(auto it = buttons.begin(); it!=buttons.end(); it++)
    {
        buttons.erase(it);
    }
}

// Functions
// update Events
void MainMenuState::updateMouseMove(int x, int y)
{
    // check if button is pressed
    for (auto it : buttons)
    {
        it.second->updateMouseMove(x,y);
    }
}

void MainMenuState::updateMousePress(int x, int y)
{
    // update Buttons
    for (auto it : buttons)
    {
        it.second->updateMousePress(x,y);
    }
}

void MainMenuState::updateMouseRelease(int x, int y)
{
    // update Buttons
    for (auto it : buttons)
    {
        it.second->updateMouseRelease(x, y);
    }
}


//
void MainMenuState::update(float deltaTime)
{
    /**
     * - update UI
    **/
    for (auto it : buttons)
    {
        it.second->update();
    }
}

void MainMenuState::draw(sf::RenderTarget &target, sf::RenderStates states) const
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

void MainMenuState::Quit()
{
    states.push(new ExitState(setting, states));
}