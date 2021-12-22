#include "Game/GameObject/Pattern/Round.h"

#include <iostream>

// UI Draw Function
void GameObject::Round::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Pattern::draw(target, states);
    target.draw(circle);
}

GameObject::Round::Round(Color &color, int &radius, std::string name) : Pattern(color, radius, name)
{
    setupShape();
}

// Private Function
void GameObject::Round::setupShape()
{
    circle.setRadius(getRadius() * 0.7);
    circle.setOutlineThickness(5);
    circle.setFillColor(getColor().getLightColor());
    circle.setOutlineColor(getColor().getDarkColor());
    sf::FloatRect rect = circle.getLocalBounds();
    circle.setOrigin(rect.left + rect.width / 2.0f,
                     rect.top + rect.height / 2.0f);
}

// Functions
void GameObject::Round::setColor(Color &color)
{
    Pattern::setColor(color);
    circle.setFillColor(color.getLightColor());
    circle.setOutlineColor(color.getDarkColor());
}

void GameObject::Round::setPosition(sf::Vector2f &point)
{
    Pattern::setPosition(point);
    circle.setPosition(point);
}

// Update Events
void GameObject::Round::updateMouseMove(sf::Vector2f &point)
{
    Pattern::updateMouseMove(point);
    circle.setPosition(point);
}