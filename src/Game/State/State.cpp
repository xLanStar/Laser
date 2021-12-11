#include "State.h"

#include <iostream>
#include <stack>

#include "Game/Game.h"

State::State(Game &game) : game(game)
{
    
}

State::~State()
{
    // Clear gameObjects
    for(auto it = gameObjects.begin(); it!=gameObjects.end(); it++)
    {
        gameObjects.erase(it);
    }
}
// UI Draw Function
void State::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw gameObjects
    for (auto it : gameObjects)
    {
        //it.second.render();
        target.draw(*it.second);
    }
}

// Accessors

void State::Quit()
{
    std::cout << "[State] Quit!\n";
    game.popState();
}

// update Events
void State::updateMouseMove(Point &point)
{
    // check if button is pressed
    for (auto it : gameObjects)
    {
        it.second->updateMouseMove(point);
    }
}

void State::updateMousePress(Point &point)
{
    // update Buttons
    for (auto it : gameObjects)
    {
        it.second->updateMousePress(point);
    }
}

void State::updateMouseRelease(Point &point)
{
    // update Buttons
    for (auto it : gameObjects)
    {
        it.second->updateMouseRelease(point);
    }
}


//
void State::update(float deltaTime)
{
    /**
     * - update UI
    **/
    for (auto it : gameObjects)
    {
        it.second->update();
    }
}