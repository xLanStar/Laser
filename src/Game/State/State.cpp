#include "State.h"

#include <iostream>

#include "Game/Game.h"

State::State(Game &game) : game(game)
{
    border.setPosition(sf::Vector2f(borderSize,borderSize));
    border.setSize(sf::Vector2f(game.setting.getWindowSize().x-borderSize*2, game.setting.getWindowSize().y-borderSize*2));
    border.setFillColor(sf::Color(0,0,0,0));
    border.setOutlineColor(sf::Color(game.setting.getColor().getDarkColor()));
    border.setOutlineThickness(borderSize);
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
    border.setOutlineColor(color.getDarkColor());
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
    target.draw(border);
}