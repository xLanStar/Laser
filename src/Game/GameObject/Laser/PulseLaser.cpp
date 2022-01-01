#include "Game/GameObject/Laser/PulseLaser.h"

#include <cmath>

#include "Game/Util.h"

void GameObject::PulseLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    if (pulsing) //釋放時
    {
        target.draw(line); //繪出實線
    }
    else //充能時
    {
        for (auto line : dashLine)
        {
            target.draw(line); //繪出虛線
        }
    }
}

GameObject::PulseLaser::PulseLaser(sf::Vector2f dashLineBeginPosition, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int thickness, float delay, float duration, int dashLineLength) : Laser(dashLineBeginPosition, color, thickness, angle, borderRect, prop), delay(delay), duration(duration), dashLineLength(dashLineLength)
{
    liveTime = delay + duration; //生存時間等於延遲時間加上脈衝持續時間

    line.setPosition(dashLineBeginPosition);     //設定位置
    line.setRotation(angle * 180 / PI);          //旋轉
    line.setFillColor(color.getDarkColor());     //設定顏色
    line.setSize(sf::Vector2f(1500, thickness)); //線長

    // Generate Dashed Lines
    sf::Vector2f dashLineRect(dashLineLength, thickness);                             //虛線的線長和線寬
    float deltaX = cos(angle) * dashLineLength, deltaY = sin(angle) * dashLineLength; //線長的 sin 和 cos 的對應
    dashLineBeginPosition.x += deltaX;
    dashLineBeginPosition.y += deltaY;
    while (borderRect.contains(dashLineBeginPosition))
    {
        dashLine.push_back(sf::RectangleShape(dashLineRect)); //增加虛線
        dashLine.back().setPosition(dashLineBeginPosition);   //設定位置
        dashLine.back().setRotation(angle * 180 / PI);        //設定角度
        dashLine.back().setFillColor(color.getDarkColor());   //設定顏色
        dashLineBeginPosition.x += deltaX * 2;                // x 增加
        dashLineBeginPosition.y += deltaY * 2;                // y 增加
    }
}

bool GameObject::PulseLaser::isCollided(const Pattern &player) const
{
    if (pulsing) //釋放時
    {
        const sf::Vector2f &playerPosition = player.getPosition();
        const sf::Vector2f &position(line.getPosition());                                                                                                //取得位置
        return distanceOfPointToLineByAngle(playerPosition.x, playerPosition.y, position.x, position.y, angle) <= player.getRadius() + line.getSize().y; //點線距離
    }
    return false; //充能時一定不會碰撞到
}

void GameObject::PulseLaser::update(float deltaTime) //更新
{
    counter += deltaTime; //增加時間變化量
    if (pulsing)          //釋放中
    {
        if (counter >= liveTime) //如果活太久了
        {
            destroy(); //消滅
        }
    }
    else
    {
        if (counter >= delay) //如果超過充能時間了
        {
            pulsing = true; //釋放
        }
    }
}
