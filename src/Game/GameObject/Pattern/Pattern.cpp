#include "Pattern.h"

#include <iostream>
#include <cmath>

#include "Game/Game.h"

void GameObject::Pattern::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(circle); //外圓
}

// Constructor
GameObject::Pattern::Pattern(Color &color, int &radius, std::string name) : GameObject(), color(color), radius(radius), name(name)
{
    setupShape();
}

// Private Functions
void GameObject::Pattern::setupShape()
{
    circle.setRadius(getRadius());                     //取得半徑
    circle.setOutlineThickness(5);                     //取得線寬
    circle.setFillColor(getColor().getLightColor());   //內部填滿亮色
    circle.setOutlineColor(getColor().getDarkColor()); //外框深色

    sf::FloatRect rect = circle.getLocalBounds();
    circle.setOrigin(rect.left + rect.width / 2.0f,
                     rect.top + rect.height / 2.0f);
}

// Accessors
std::string &GameObject::Pattern::getName() //取得 Pattern 名稱
{
    return name;
}

int &GameObject::Pattern::getRadius() //取得半徑
{
    return radius;
}

Color &GameObject::Pattern::getColor() //取得 Color 物件
{
    return color;
}

// Functions
void GameObject::Pattern::setColor(Color &color)
{
    circle.setFillColor(color.getLightColor());
    circle.setOutlineColor(color.getDarkColor());
}

void GameObject::Pattern::setPosition(sf::Vector2f &position) //設定位置
{
    // GameObject::setPosition(position);
    circle.setPosition(position);
}

void GameObject::Pattern::updateMouseMove(sf::Vector2f &point) // Pattern移動到玩家的位置
{
    circle.setPosition(point);
}