#include "Pantone.h"

#include <cmath>

#include "Game/Util.h"

GameObject::Pantone::Pantone(sf::Vector2f position, Color &color, sf::SoundBuffer &soundBuffer, std::function<void()> onClick, int points, int radius, float hoverScale) : GameObject(color, position), onClick(onClick), pressed(false), points(points), radius(radius), hoverScale(hoverScale)
{
    setupShape(); // 設定圖案
    sound.setBuffer(soundBuffer);
}

int GameObject::Pantone::getRadius() const // 取得半徑
{
    return radius;
}

void GameObject::Pantone::setupShape() // 設定型狀
{
    setPosition(position);

    leftConvex.setPointCount(points);  // 多邊形的點數量
    rightConvex.setPointCount(points); // 多邊形的點數量

    leftConvex.setFillColor(color.getDarkColor());   // 設定暗色
    rightConvex.setFillColor(color.getLightColor()); // 設定亮色

    const double step = PI / points;

    double angle = -PI / 2;
    rightConvex.setPoint(0, sf::Vector2f(cos(angle) * radius, sin(angle) * radius));
    for (int i = 1; i < points - 1; i++)
    {
        rightConvex.setPoint(i, sf::Vector2f(cos(angle + step * i) * radius, sin(angle + step * i) * radius));
    }
    rightConvex.setPoint(points - 1, sf::Vector2f(cos(angle + PI) * radius, sin(angle + PI) * radius));

    angle = PI / 2;
    leftConvex.setPoint(0, sf::Vector2f(cos(angle) * radius, sin(angle) * radius));
    for (int i = 1; i < points - 1; i++)
    {
        leftConvex.setPoint(i, sf::Vector2f(cos(angle + step * i) * radius, sin(angle + step * i) * radius));
    }
    leftConvex.setPoint(points - 1, sf::Vector2f(cos(angle + PI) * radius, sin(angle + PI) * radius));
}

void GameObject::Pantone::setPosition(sf::Vector2f position) // 設定位置
{
    leftConvex.setPosition(position);
    rightConvex.setPosition(position);
}

void GameObject::Pantone::updateMouseMove(sf::Vector2f &point) // 滑鼠移動
{
    if (leftConvex.getGlobalBounds().contains(point) || rightConvex.getGlobalBounds().contains(point))
    {
        if (!hover)
        {
            hover = true;
            rightConvex.setScale(sf::Vector2f(hoverScale, hoverScale));
            leftConvex.setScale(sf::Vector2f(hoverScale, hoverScale));
        }
    }
    else
    {
        if (hover)
        {
            hover = false;
            rightConvex.setScale(sf::Vector2f(1.f, 1.f));
            leftConvex.setScale(sf::Vector2f(1.f, 1.f));
        }
    }
}

void GameObject::Pantone::updateMousePress(sf::Vector2f &point) // 滑鼠按下
{
    if (hover && !pressed) //如果被覆蓋又被壓
    {
        sound.play();
        pressed = true; //狀態改為被壓著
    }
}

void GameObject::Pantone::updateMouseRelease(sf::Vector2f &point) // 滑鼠放開
{
    pressed = false; // 釋放
    if (hover)       // 如果被覆蓋
    {
        onClick(); // 觸發點擊事件
    }
}

void GameObject::Pantone::draw(sf::RenderTarget &target, sf::RenderStates states) const // 渲染
{
    target.draw(leftConvex);  //畫左邊
    target.draw(rightConvex); //畫右邊
}