#include "Pattern.h"

#include <iostream>
#include <cmath>

#include "Game/Game.h"

// UI Draw Function
void GameObject::Pattern::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(circle);
}

// Constructor
GameObject::Pattern::Pattern(Color &color, int &radius, std::string name) : GameObject(), color(color), radius(radius), name(name)
{
    setupShape();
}

// Private Functions
void GameObject::Pattern::setupShape()
{
    circle.setRadius(getRadius());
    circle.setOutlineThickness(5);
    circle.setFillColor(getColor().getLightColor());
    circle.setOutlineColor(getColor().getDarkColor());

    sf::FloatRect rect = circle.getLocalBounds();
    circle.setOrigin(rect.left + rect.width / 2.0f,
                     rect.top + rect.height / 2.0f);
}

// Accessors
std::string &GameObject::Pattern::getName()
{
    return name;
}

int &GameObject::Pattern::getRadius()
{
    return radius;
}

Color &GameObject::Pattern::getColor()
{
    return color;
}

// Functions
void GameObject::Pattern::setColor(Color &color)
{
    circle.setFillColor(color.getLightColor());
    circle.setOutlineColor(color.getDarkColor());
}

void GameObject::Pattern::setPosition(sf::Vector2f &position)
{
    GameObject::setPosition(position);
    circle.setPosition(position);
}

// Mouse Move
void GameObject::Pattern::updateMouseMove(sf::Vector2f &point)
{
    circle.setPosition(point);
}