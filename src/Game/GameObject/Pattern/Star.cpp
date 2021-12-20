#include "Game/GameObject/Pattern/Star.h"

#include <cmath>
#include <iostream>

#define PI 3.14159265358979323846

// UI Draw Function
void GameObject::Star::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Pattern::draw(target, states);
    target.draw(star);
}

GameObject::Star::Star(Color &color, int &radius, std::string name) : Pattern(color, radius, name)
{
    setupShape();
}

GameObject::Star::~Star()
{
}

// Private Function
void GameObject::Star::setupShape()
{
    starSize = getRadius() * 0.7;

    star.setOutlineThickness(5);
    star.setFillColor(getColor().getLightColor());
    star.setOutlineColor(getColor().getDarkColor());
    sf::FloatRect rect = star.getLocalBounds();
    star.setOrigin(rect.left + rect.width / 2.0f,
                   rect.top + rect.height / 2.0f);
    star.setPointCount(10);
    for (int i = 1; i <= 5; i++)
    {
        star.setPoint(i * 2 - 2, sf::Vector2f(cos((18 + 72 * i) * PI / 180) * starSize, -sin((18 + 72 * i) * PI / 180) * starSize));
        star.setPoint(i * 2 - 1, sf::Vector2f(cos((54 + 72 * i) * PI / 180) * starSize / 2, -sin((54 + 72 * i) * PI / 180) * starSize / 2));
    }
}

// Functions
void GameObject::Star::setColor(Color &color)
{
    Pattern::setColor(color);
    star.setFillColor(color.getLightColor());
    star.setOutlineColor(color.getDarkColor());
}

void GameObject::Star::setPosition(sf::Vector2f &point)
{
    Pattern::setPosition(point);
    star.setPosition(point);
}

// Update Events
void GameObject::Star::updateMouseMove(sf::Vector2f &point)
{
    Pattern::updateMouseMove(point);
    star.setPosition(point);
}

void GameObject::Star::updateMousePress(sf::Vector2f &point)
{
}

void GameObject::Star::updateMouseRelease(sf::Vector2f &point)
{
}

void GameObject::Star::update(float &deltaTime)
{
}