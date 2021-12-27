#include "Game/GameObject/Pattern/Round.h"

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

void GameObject::Round::setColor(Color &color)
{
    Pattern::setColor(color);
    round.setFillColor(color.getLightColor());
    round.setOutlineColor(color.getDarkColor());
}

void GameObject::Round::setPosition(sf::Vector2f point)
{
    Pattern::setPosition(point);
    round.setPosition(point);
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