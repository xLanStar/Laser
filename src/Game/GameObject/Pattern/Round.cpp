#include "Game/GameObject/Pattern/Round.h"

#include <iostream>

GameObject::Round::Round(Color &color, int &radius, std::string name) : Pattern(color, radius, name)
{
    setupShape();
}

// Private Function
void GameObject::Round::setupShape() //設定形狀
{
    round.setRadius(radius * 0.7);
    round.setOutlineThickness(5);
    round.setFillColor(color.getLightColor());
    round.setOutlineColor(color.getDarkColor());
    sf::FloatRect rect = round.getLocalBounds();
    round.setOrigin(rect.left + rect.width / 2.0f,
                    rect.top + rect.height / 2.0f);
}

// Update Events
void GameObject::Round::updateMouseMove(sf::Vector2f &position)
{
    Pattern::updateMouseMove(position);
    round.setPosition(position);
}
// UI Draw Function
void GameObject::Round::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Pattern::draw(target, states);
    target.draw(round);
}