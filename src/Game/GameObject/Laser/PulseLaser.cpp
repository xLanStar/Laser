#include "Game/GameObject/Laser/PulseLaser.h"

#include <cmath>
#include <iostream>

#include "Game/Util.h"

// UI Draw Function
void GameObject::PulseLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (showHitBox)
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

GameObject::PulseLaser::PulseLaser(sf::Vector2f position, int &thickness, float &angle, float &delay, float &powerTime, float &duration, int &dashLineLength, int &dashLineThickness, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop) : Laser(position, color, thickness, borderRect, prop), angle(angle), delay(delay), duration(duration), dashLineLength(dashLineLength), thickness(thickness), powerTime(powerTime)
{
    liveTime = delay + duration;
    deltaThickness = thickness / (duration * powerTime);
    deltaShake = sf::Vector2f(cos(angle + PI / 2), sin(angle + PI / 2));
    std::cout << "deltaShake : " << deltaShake.x << ", " << deltaShake.y << '\n';

    line.setPosition(position);
    line.setRotation(angle * 180 / PI);
    line.setOutlineColor(color.getDarkColor());
    line.setSize(sf::Vector2f(1500, 0));

    // ((crossProduct v1, v) * (crossProduct v2, v) >= 0 )
    // (ax * cy + ay * cx) * (bx * cy + by *cx) >= 0
    if (true)
    {
        box.setSize(sf::Vector2f(32, 32));
        box.setOrigin(sf::Vector2f(16, 16));
        box.setPosition(position);
        box.setFillColor(sf::Color(0, 0, 0, 0));
        box.setOutlineColor(sf::Color(255, 0, 0));
        box.setOutlineThickness(10);
    }
    // line.setSize(sf::Vector2f(length, 0));

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
    if (pulsing)
    {
        sf::Vector2f position(line.getPosition());
        return distanceOfPointToLineByAngle(point.x, point.y, position.x, position.y, angle) <= radius + line.getSize().y;
    }
    return false;
}

void GameObject::PulseLaser::update(float &deltaTime)
{
    counter += deltaTime;
    if (pulsing)
    {
        if (counter >= liveTime)
        {
            destroy();
        }
        else
        {
            line.setPosition(getPosition() + deltaShake * static_cast<float>(rand() % 5 - 5));
            if (line.getOutlineThickness() < thickness)
            {
                line.setOutlineThickness(line.getOutlineThickness() + deltaThickness * deltaTime);
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
