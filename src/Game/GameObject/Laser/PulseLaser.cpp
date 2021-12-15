#include "Game/GameObject/Laser/PulseLaser.h"

#include <cmath>
#include <iostream>

#include "Game/Util.h"

// UI Draw Function
void GameObject::PulseLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(showHitBox)
    {
        target.draw(box);
    }
    if (pulsing)
    {
        target.draw(line);
    }
    else
    {
        for (auto line : dashLine)
        {
            target.draw(line);
        }
    }
}

GameObject::PulseLaser::PulseLaser(sf::Vector2f position, int &thickness, float &angle, float &delay, float &duration, int &dashLineLength, int &dashLineThickness, Color &color, sf::FloatRect &borderRect) : Laser(position, color, thickness, borderRect), angle(angle), delay(delay), duration(duration), dashLineLength(dashLineLength), thickness(thickness)
{
    std::cout << "[PulseLaser] " << position.x << ", " << position.y << '\n';
    liveTime = delay + duration;
    deltaThickness = thickness / (duration * powerTime);

    line.setPosition(position);
    line.setRotation(angle);
    line.setFillColor(color.getDarkColor());



    // ((crossProduct v1, v) * (crossProduct v2, v) >= 0 )
    // (ax * cy + ay * cx) * (bx * cy + by *cx) >= 0
    if((borderRect.left * position.y + borderRect.top * position.x) * ((borderRect.left+borderRect.width) *position.y + borderRect.top * position.x) >= 0)
    {
        box.setSize(sf::Vector2f(20,20));
        box.setOrigin(sf::Vector2f(10,10));
        box.setPosition(position);
        box.setFillColor(sf::Color(0,0,0,0));
        box.setOutlineColor(color.getDarkColor());
        box.setOutlineThickness(10);
        std::cout << "between A and B\n";
    }
    //line.setSize(sf::Vector2f(length, 0));

    // Generate Dashed Lines
    sf::Vector2f dashLineRect(dashLineLength, dashLineThickness);
    sf::Vector2f dashPosition = position;
    float deltaX = cos(angle) * dashLineLength, deltaY = sin(angle) * dashLineLength;
    for (; inRange(dashPosition.x + deltaX, dashPosition.y + deltaY, borderRect.left, borderRect.top, borderRect.left + borderRect.width, borderRect.top + borderRect.height);)
    {
        dashLine.push_back(sf::RectangleShape(dashLineRect));
        dashLine.back().setPosition(dashPosition);
        dashLine.back().setRotation(angle * 180 / PI);
        dashLine.back().setFillColor(color.getDarkColor());
        dashPosition.x += deltaX * 2;
        dashPosition.y += deltaY * 2;
    }
    std::cout << dashLine.size() << '\n';
}

GameObject::PulseLaser::~PulseLaser()
{
}

// Accessors
void GameObject::PulseLaser::setColor(Color &color)
{
}

void GameObject::PulseLaser::setPosition(sf::Vector2f &point)
{
}

bool GameObject::PulseLaser::isCollided(sf::Vector2f &point, int &radius)
{
    if(pulsing)
    {
        // TODO: distanceOfPointToLine
    }
    return false;
}

// Update Events
void GameObject::PulseLaser::updateMouseMove(sf::Vector2f &point)
{
}

void GameObject::PulseLaser::updateMousePress(sf::Vector2f &point)
{
}

void GameObject::PulseLaser::updateMouseRelease(sf::Vector2f &point)
{
}

void GameObject::PulseLaser::update(float &deltaTime)
{
    counter += deltaTime;
    if (pulsing)
    {
        if (counter >= liveTime)
        {
            std::cout << "[PulseLaser] death\n";
            destroy();
        }
        else
        {
            if(line.getSize().y < thickness)
            {
                line.setSize(sf::Vector2f(line.getSize().x, line.getSize().y + deltaThickness * deltaTime));
            }
        }
    }
    else
    {
        if (counter >= delay)
        {
            // Pulse
            pulsing = true;
        }
        else
        {
            // waiting
        }
    }
}
