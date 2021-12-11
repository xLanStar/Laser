#include "Pantone.h"

#include <iostream>
#include <cmath>

#include "Game/Game.h"

#define PI 3.14159265358979323846

// UI Draw Function
void GameObject::Pantone::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(leftConvex);
    target.draw(rightConvex);
}

// Constructor
GameObject::Pantone::Pantone(Point position, int &points, int &radius, float &hoverScale, Color &color, std::function<void()> onClick) : GameObject(position), color(color), onClick(onClick), pressed(false), points(points), radius(radius), hoverScale(hoverScale)
{
    setupShape();
}

GameObject::Pantone::~Pantone()
{
}

// Accessors
int &GameObject::Pantone::getRadius()
{
    return radius;
}

// Functions
void GameObject::Pantone::setupShape()
{
    // set Position
    setPosition(getPosition());

    // set Point Count
    leftConvex.setPointCount(points);
    rightConvex.setPointCount(points);

    // set Fill Color
    leftConvex.setFillColor(color.darkColor);
    rightConvex.setFillColor(color.lightColor);

    // set Shape Points
    const double step = PI / points;

    // Right
    double angle = -PI / 2;
    rightConvex.setPoint(0, sf::Vector2f(cos(angle) * radius, sin(angle) * radius));
    for (int i = 1; i < points - 1; i++)
    {
        rightConvex.setPoint(i, sf::Vector2f(cos(angle + step * i) * radius, sin(angle + step * i) * radius));
    }
    rightConvex.setPoint(points - 1, sf::Vector2f(cos(angle + PI) * radius, sin(angle + PI) * radius));
    // Left
    angle = PI / 2;
    leftConvex.setPoint(0, sf::Vector2f(cos(angle) * radius, sin(angle) * radius));
    for (int i = 1; i < points - 1; i++)
    {
        leftConvex.setPoint(i, sf::Vector2f(cos(angle + step * i) * radius, sin(angle + step * i) * radius));
    }
    leftConvex.setPoint(points - 1, sf::Vector2f(cos(angle + PI) * radius, sin(angle + PI) * radius));
}

void GameObject::Pantone::setHover(bool isHovered)
{
    hover = isHovered;
    if (hover)
    {
        rightConvex.setScale(sf::Vector2f(hoverScale, hoverScale));
        leftConvex.setScale(sf::Vector2f(hoverScale, hoverScale));
    }
    else
    {
        rightConvex.setScale(sf::Vector2f(1.f, 1.f));
        leftConvex.setScale(sf::Vector2f(1.f, 1.f));
    }
}

void GameObject::Pantone::setPosition(Point &position)
{
    GameObject::setPosition(position);
    leftConvex.setPosition(position.x, position.y);
    rightConvex.setPosition(position.x, position.y);
}

// void GameObject::Pantone::setPoints(int &points)
// {
//     this->points = points;
// }
// void GameObject::Pantone::setRadius(int &radius)
// {
//     this->radius = radius;
// }

// void GameObject::Pantone::setHoverScale(float &hoverScale)
// {
//     this->hoverScale = hoverScale;
// }

// void GameObject::Pantone::setColor(Color &color)
// {
//     this->color = color;
// }

// Mouse Move
void GameObject::Pantone::updateMouseMove(Point &point)
{
    if (leftConvex.getGlobalBounds().contains(point.x, point.y) || rightConvex.getGlobalBounds().contains(point.x, point.y))
    {
        if (!hover)
        {
            setHover(true);
            // std::cout << "[Pantone] " << color.name << " Hover In!\n";
        }
    }
    else
    {
        if (hover)
        {
            setHover(false);
            // std::cout << "[Pantone] " << color.name << " Hover Out!\n";
        }
    }
}

// Mouse Press
void GameObject::Pantone::updateMousePress(Point &point)
{
    if (hover && !pressed)
    {
        pressed = true;
        // std::cout << "[Pantone] " << color.name << " Mouse Press!\n";
    }
}

// Mouse Release
void GameObject::Pantone::updateMouseRelease(Point &point)
{
    if (pressed)
    {
        pressed = false;
        if (hover)
        {
            onClick();
            // std::cout << "[Pantone] " << color.name << " Triggered!\n";
        }
        // std::cout << "[Pantone] " << color.name << " Released!\n";
    }
}

void GameObject::Pantone::update()
{
}