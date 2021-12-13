#include "Game/GameObject/Laser/NormalLaser.h"

#include <cmath>
#include <iostream>

#include "Game/Util.h"

// UI Draw Function
void GameObject::NormalLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(line);
    if(debugged)
    {
        target.draw(box);
        target.draw(box2);
    }
}

GameObject::NormalLaser::NormalLaser(sf::Vector2f position, sf::Vector2f &rect, float &angle, float &velocity, Color &color, int &borderSize, sf::Vector2f &windowRect) : Laser(borderSize), angle(angle), velocity(velocity), rect(rect), length(rect.x), borderSize(borderSize), windowRect(windowRect)
{
    std::cout << position.x << ", " << position.y << '\n';
    line.setFillColor(sf::Color(255, 255, 255));
    line = sf::RectangleShape(sf::Vector2f(0, rect.y));
    line.setFillColor(color.getDarkColor());
    line.setPosition(position);
    line.setRotation(angle * 180 / PI + 180);
    deltaX = cos(angle) * velocity;
    deltaY = sin(angle) * velocity;
    endX = position.x;
    endY = position.y;
    
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
    int currentLength = line.getSize().x;
    sf::Vector2f startPosition = line.getPosition();
    float endX = startPosition.x - cos(angle) * currentLength, endY = startPosition.y - sin(angle) * currentLength;
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
    sf::Vector2f offset(deltaX * deltaTime, deltaY * deltaTime);
    if (borderSize <= line.getPosition().x && line.getPosition().x <= windowRect.x - borderSize && borderSize <= line.getPosition().y && line.getPosition().y <= windowRect.y - borderSize)
    {
        line.move(offset);
        if (line.getSize().x < length)
        {
            line.setSize(sf::Vector2f(line.getSize().x + velocity * deltaTime, rect.y));
        }
        else
        {
            endX += offset.x;
            endY += offset.y;
        }
    }
    else
    {
        if (line.getSize().x > 0)
        {
            line.setSize(sf::Vector2f(line.getSize().x - velocity * deltaTime, rect.y));
            endX += offset.x;
            endY += offset.y;
        }
        else
        {
            destroy();
        }
    }
    
    if(debugged)
    {
        box.setPosition(endX, endY);
        box2.setPosition(line.getPosition().x, line.getPosition().y);
    }
    else
    {

    }
}
