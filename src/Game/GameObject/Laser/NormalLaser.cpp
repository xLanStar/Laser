#include "Game/GameObject/Laser/NormalLaser.h"

#include <cmath>
#include <iostream>

#include "Game/Util.h"

// UI Draw Function
void GameObject::NormalLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(line);
    if (showHitBox)
    {
        target.draw(box);
        target.draw(box2);
    }
}

GameObject::NormalLaser::NormalLaser(sf::Vector2f position, int &length, int &thickness, float &angle, float &velocity, Color &color, sf::FloatRect &borderRect) : Laser(position, color, thickness, borderRect), angle(angle), velocity(velocity), length(length)
{
    line.setFillColor(sf::Color(255, 255, 255));
    line = sf::RectangleShape(sf::Vector2f(0, thickness));
    line.setFillColor(color.getDarkColor());
    line.setPosition(position);
    line.setRotation(angle * 180 / PI + 180);
    deltaX = cos(angle) * velocity;
    deltaY = sin(angle) * velocity;
    endX = position.x;
    endY = position.y;

    // Debug Box
    box.setSize(sf::Vector2f(16, 16));
    box.setOrigin(8, 8);
    box.setOutlineColor(sf::Color(255, 0, 0));
    box.setOutlineThickness(5);
    box.setFillColor(sf::Color(0, 0, 0, 0));

    box2.setSize(sf::Vector2f(16, 16));
    box2.setOrigin(8, 8);
    box2.setOutlineColor(sf::Color(255, 0, 0));
    box2.setOutlineThickness(5);
    box2.setFillColor(sf::Color(0, 0, 0, 0));
}

GameObject::NormalLaser::~NormalLaser()
{
}

// Accessors
void GameObject::NormalLaser::setColor(Color &color)
{
}

void GameObject::NormalLaser::setPosition(sf::Vector2f &point)
{
}

bool GameObject::NormalLaser::isCollided(sf::Vector2f &point, int &radius)
{
    sf::Vector2f startPosition = line.getPosition();

    int distance = distanceOfPointToSeg(point.x, point.y, startPosition.x, startPosition.y, endX, endY);

    return distance <= radius;
}

// Update Events
void GameObject::NormalLaser::updateMouseMove(sf::Vector2f &point)
{
}

void GameObject::NormalLaser::updateMousePress(sf::Vector2f &point)
{
}

void GameObject::NormalLaser::updateMouseRelease(sf::Vector2f &point)
{
}

void GameObject::NormalLaser::update(float &deltaTime)
{
    // move offset
    sf::Vector2f offset(deltaX * deltaTime, deltaY * deltaTime);
    
    if (inRange(line.getPosition().x, line.getPosition().y, getBorderRect().left, getBorderRect().top, getBorderRect().left + getBorderRect().width, getBorderRect().top + getBorderRect().height))
    {
        // in laser border
        line.move(offset);
        if (line.getSize().x < length)
        {
            line.setSize(sf::Vector2f(line.getSize().x + velocity * deltaTime, getThickness()));
        }
        else
        {
            endX += offset.x;
            endY += offset.y;
        }
    }
    else
    {
        // touch laser border
        if (line.getSize().x > 0)
        {
            line.setSize(sf::Vector2f(line.getSize().x - velocity * deltaTime, getThickness()));
            endX += offset.x;
            endY += offset.y;
        }
        else
        {
            // destroy laser
            destroy();
        }
    }

    if (showHitBox)
    {
        box.setPosition(endX, endY);
        box2.setPosition(line.getPosition().x, line.getPosition().y);
    }
}
