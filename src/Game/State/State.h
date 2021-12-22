#pragma once

#include <stack>

#include <SFML/Graphics.hpp>

#include "Game/Setting.h"
#include "Game/GameObject/GameObject.h"

class Game;

class State : public sf::Drawable
{
private:
protected:
public:
    // Reference
    Game &game;

    // UI
    std::map<std::string, GameObject::GameObject *> gameObjects; //模式文字對應到模式物件

    // Constructor
    State(Game &game);
    virtual ~State();

    // Functions
    virtual void Quit();

    // Virtual Functions
    virtual void setColor(Color &color); //設定顏色
    virtual void updateMouseMove(sf::Vector2f &point);
    virtual void updateMousePress(sf::Vector2f &point);
    virtual void updateMouseRelease(sf::Vector2f &point);
    virtual void update(float &deltaTime);

    // UI Draw Function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};