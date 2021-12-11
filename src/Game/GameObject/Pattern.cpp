#include "Pattern.h"

#include <iostream>
#include <cmath>

#include "Game/Game.h"

// UI Draw Function
void GameObject::Pattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    //TODO:
}

// Constructor
GameObject::Pattern::Pattern(Point position) : GameObject(position)
{
}

GameObject::Pattern::Pattern() : GameObject()
{
}

GameObject::Pattern::~Pattern()
{
}


void GameObject::Pattern::setupShape()
{
    //TODO:
}

void GameObject::Pattern::setPosition(Point &position)
{
    GameObject::setPosition(position);
}


// Mouse Move
void GameObject::Pattern::updateMouseMove(Point &point)
{
}

// Mouse Press
void GameObject::Pattern::updateMousePress(Point &point)
{
}

// Mouse Release
void GameObject::Pattern::updateMouseRelease(Point &point)
{
}

void GameObject::Pattern::update()
{
}