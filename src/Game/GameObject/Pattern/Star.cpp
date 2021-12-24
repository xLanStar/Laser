#include "Game/GameObject/Pattern/Star.h"

#include <cmath>
#include <iostream>

#define PI 3.14159265358979323846

// UI Draw Function
void GameObject::Star::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    Pattern::draw(target, states);
    target.draw(star);
}

GameObject::Star::Star(Color &color, int &radius, std::string name) : Pattern(color, radius, name)
{
    setupShape();
}

void GameObject::Star::setupShape() //繪製星星
{
    starSize = radius * 0.7;
    star.setOutlineThickness(5);
    star.setFillColor(color.getLightColor());
    star.setOutlineColor(color.getDarkColor());
    sf::FloatRect rect = star.getLocalBounds();
    star.setOrigin(rect.left + rect.width / 2.0f,
                   rect.top + rect.height / 2.0f);

    star.setPointCount(10); //多邊形點個數
    for (int i = 1; i <= 5; i++)
    {
        star.setPoint(i * 2 - 2, sf::Vector2f(cos((18 + 72 * i) * PI / 180) * starSize, -sin((18 + 72 * i) * PI / 180) * starSize));
        star.setPoint(i * 2 - 1, sf::Vector2f(cos((54 + 72 * i) * PI / 180) * starSize / 2, -sin((54 + 72 * i) * PI / 180) * starSize / 2));
    }
}

// Update Events
void GameObject::Star::updateMouseMove(sf::Vector2f &point)
{
    Pattern::updateMouseMove(point);
    star.setPosition(point);
}