#include "Game/GameObject/PatternTile.h"

#include <iostream>

// UI Draw Function
void GameObject::PatternTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    //target.draw(text, states);
}

// Constructor & Deconstructor
GameObject::PatternTile::PatternTile(Point position) : Tile(position)
{

}
GameObject::PatternTile::~PatternTile()
{

}

void GameObject::PatternTile::setPosition(Point &point)
{
    GameObject::setPosition(point);
}

// Mouse Move
void GameObject::PatternTile::updateMouseMove(Point &point)
{
}

// Mouse Press
void GameObject::PatternTile::updateMousePress(Point &point)
{
}

// Mouse Release
void GameObject::PatternTile::updateMouseRelease(Point &point)
{
}

void GameObject::PatternTile::update()
{
}