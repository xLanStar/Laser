#include "State.h"

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


// Accessors

void State::Quit()
{
    game.popState();
}

// Functions
void State::setColor(Color &color)
{
    for(auto it : gameObjects)
    {
        it.second->setColor(color);
    }
}

// update Events
void State::updateMouseMove(sf::Vector2f &point)
{
    // check if button is pressed
    for (auto it : gameObjects)
    {
        it.second->updateMouseMove(point);
    }
}

void State::updateMousePress(sf::Vector2f &point)
{
    // update Buttons
    for (auto it : gameObjects)
    {
        it.second->updateMousePress(point);
    }
}

void State::updateMouseRelease(sf::Vector2f &point)
{
    // update Buttons
    for (auto it : gameObjects)
    {
        it.second->updateMouseRelease(point);
    }
}


//
void State::update(float &deltaTime)
{
    /**
     * - update UI
    **/
    for (auto it : gameObjects)
    {
        it.second->update(deltaTime);
    }
}


// UI Draw Function
void State::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw gameObjects
    for (auto &it : gameObjects)
    {
        target.draw(*it.second);
    }
}