#include "Pantone.h"

#include <cmath>

#include "Game/Util.h"

// UI Draw Function
void GameObject::Pantone::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(leftConvex);  //畫左邊
    target.draw(rightConvex); //畫右邊
}

// Constructor
GameObject::Pantone::Pantone(sf::Vector2f position, int points, int radius, float hoverScale, Color &color, std::function<void()> onClick) : GameObject(position, color), color(color), onClick(onClick), pressed(false), points(points), radius(radius), hoverScale(hoverScale)
{
    setupShape(); //設定圖案
}

// Accessors
int &GameObject::Pantone::getRadius() const
{
    return radius;
}

// Functions
void GameObject::Pantone::setupShape()
{
    setPosition(getPosition()); //設定位置

    leftConvex.setPointCount(points); //設定位置
    rightConvex.setPointCount(points);

    leftConvex.setFillColor(color.getDarkColor());
    rightConvex.setFillColor(color.getLightColor());

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

void GameObject::Pantone::setColor(Color &color)
{
}

void GameObject::Pantone::setPosition(sf::Vector2f &position)
{
    GameObject::setPosition(position);
    leftConvex.setPosition(position.x, position.y);
    rightConvex.setPosition(position.x, position.y);
}

// Mouse Move
void GameObject::Pantone::updateMouseMove(sf::Vector2f &point)
{
    if (leftConvex.getGlobalBounds().contains(point.x, point.y) || rightConvex.getGlobalBounds().contains(point.x, point.y))
    {
        if (!hover)
        {
            setHover(true);
        }
    }
    else
    {
        if (hover)
        {
            setHover(false);
        }
    }
}

// Mouse Press
void GameObject::Pantone::updateMousePress(sf::Vector2f &point)
{
    if (hover && !pressed) //如果被覆蓋又被壓
    {
        pressed = true; //狀態改為被壓著
    }
}

// Mouse Release
void GameObject::Pantone::updateMouseRelease(sf::Vector2f &point)
{
    if (pressed) //如果被按著
    {
        pressed = false; //改為放開
        if (hover)       //如果被覆蓋
        {
            onClick(); //觸發點擊事件
        }
    }
}