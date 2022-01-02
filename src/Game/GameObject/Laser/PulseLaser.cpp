#include "Game/GameObject/Laser/PulseLaser.h"

#include <cmath>

#include "Game/Util.h"

void GameObject::PulseLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    if (pulsing) //釋放時
    {
        target.draw(line); //繪出實線
    }
    else if (counter < liveTime) //充能時
    {
        for (auto line : dashLine)
        {
            target.draw(line); //繪出虛線
        }
    }
}

GameObject::PulseLaser::PulseLaser(sf::Vector2f dashLineBeginPosition, float arc, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int thickness, float delay, float duration, int dashLineLength) : Laser(dashLineBeginPosition, color, thickness, arc, borderRect, prop), delay(delay), duration(duration), dashLineLength(dashLineLength)
{
    liveTime = delay + duration; //計算總生存時間：延遲時間加上脈衝持續時間

    line.setPosition(dashLineBeginPosition);     //設定位置
    line.setRotation(arcToDeg(arc));             //旋轉
    line.setFillColor(color.getDarkColor());     //設定顏色
    line.setSize(sf::Vector2f(1500, thickness)); //線長

    //生成虛線
    sf::Vector2f dashLineRect(dashLineLength, thickness); //虛線的線長和線寬
    float deltaX = cos(arc) * dashLineLength;             //取得 cos 位移
    float deltaY = sin(arc) * dashLineLength;             //取得 sin 位移
    dashLineBeginPosition.x += deltaX;                    //計算偏移量
    dashLineBeginPosition.y += deltaY;                    //計算偏移量
    while (borderRect.contains(dashLineBeginPosition))
    {
        dashLine.push_back(sf::RectangleShape(dashLineRect)); //增加虛線
        dashLine.back().setPosition(dashLineBeginPosition);   //設定位置
        dashLine.back().setRotation(arcToDeg(arc));           //設定角度
        dashLine.back().setFillColor(color.getDarkColor());   //設定顏色
        dashLineBeginPosition.x += deltaX * 2;                // x 增加
        dashLineBeginPosition.y += deltaY * 2;                // y 增加
    }

    particleSystem.setPosition(dashLineBeginPosition); //設定位置
    particleSystem.setRotation(arc);                   //設定角度
    particleSystem.setShape(Line, line.getSize().x);   //設定形狀
}

bool GameObject::PulseLaser::isCollided(const Pattern &player) const
{
    if (pulsing) //釋放時
    {
        const sf::Vector2f &playerPosition = player.getPosition();                                                                                   //取得玩家的圓心位置
        const sf::Vector2f &position(line.getPosition());                                                                                            //取得線的位置
        return distanceOfPointToLineByArc(playerPosition.x, playerPosition.y, position.x, position.y, arc) <= player.getRadius() + line.getSize().y; //點到線距離
    }
    return false; //充能時一定碰撞
}

void GameObject::PulseLaser::update(float deltaTime) //更新
{
    counter += deltaTime; //增加時間變化量
    if (pulsing)          //釋放中
    {
        if (counter >= liveTime) //如果活太久了
        {
            pulsing = false;                                //停止釋放
            particleSystem.setPosition(line.getPosition()); //設定位置
            particleSystem.Emit();                          //啟動粒子系統並且發射
        }
    }
    else if (counter < liveTime) //充能中
    {
        if (counter >= delay) //如果超過充能時間了
        {
            pulsing = true; //釋放
        }
    }
    else //釋放完
    {
        if (!particleSystem.isAlive()) //如果粒子效果結束了
        {
            destroy(); //刪除
        }
    }
    particleSystem.update(deltaTime); //更新粒子系統
}
