#pragma once

#include <stack>

#include <SFML/Graphics.hpp>

#include "Game/Setting.h"
#include "Game/GameObject/GameObject.h"

class Game;

class State : public sf::Drawable
{
private:
    // UI Draw Function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
protected:
public:
    // Reference
    Game &game;

    // UI
    std::map<std::string, GameObject::GameObject *> gameObjects;

    // Constructor
    State(Game &game);
    virtual ~State();

    // Functions
    virtual void Quit();

    // Virtual Functions
    virtual void updateMouseMove(Point &point);
    virtual void updateMousePress(Point &point);
    virtual void updateMouseRelease(Point &point);
    virtual void update(float deltaTime);
    // virtual void render() = 0;
};