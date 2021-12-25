#include "State.h"

#include "Game/Game.h"

State::State(Game &game) : game(game)
{
}

State::~State()
{
    // Clear gameObjects
    for (auto it = gameObjects.begin(); it != gameObjects.end(); it++) //清除容器內的所有物件
    {
        gameObjects.erase(it); //清除
    }
}

void State::Quit() //將堆疊的狀態 Pop
{
    game.popState();
}

// Functions
void State::setColor(Color &color)
{
    for (auto it : gameObjects)
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

void State::update(float &deltaTime) //更新
{
    for (auto it : gameObjects)
    {
        it.second->update(deltaTime);
    }
}

void State::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    for (auto &it : gameObjects) //將容器內的所有 GameObject 渲染
    {
        target.draw(*it.second);
    }
}