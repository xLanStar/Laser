#include "Game/GameObject/Laser/PulseLaser.h"

#include <cmath>

#include "Game/Util.h"

void GameObject::PulseLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    // if (showHitBox)
    // {
    //     target.draw(box);
    // }
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

GameObject::PulseLaser::PulseLaser(sf::Vector2f position, int thickness, float angle, float delay, float powerTime, float duration, int dashLineLength, int dashLineThickness, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop) : Laser(position, color, thickness, borderRect, prop), angle(angle), delay(delay), duration(duration), dashLineLength(dashLineLength), thickness(thickness), powerTime(powerTime)
{
    liveTime = delay + duration; //生存時間等於延遲時間加上脈衝持續時間
    deltaThickness = thickness / (duration * powerTime);

    deltaShake = sf::Vector2f(cos(angle + PI / 2), sin(angle + PI / 2));

    line.setPosition(position);                 //設定位置
    line.setRotation(angle * 180 / PI);         //旋轉
    line.setOutlineColor(color.getDarkColor()); //設定顏色
    line.setSize(sf::Vector2f(1500, 0));        //線長
    line.setOutlineThickness(thickness);        //設定線寬

    // Generate Dashed Lines
    sf::Vector2f dashLineRect(dashLineLength, dashLineThickness);                     //儲存線長和線寬
    sf::Vector2f dashPosition = position;                                             //儲存位置
    float deltaX = cos(angle) * dashLineLength, deltaY = sin(angle) * dashLineLength; //線長的 sin 和 cos 的對應
    while (inRange(dashPosition.x + deltaX, dashPosition.y + deltaY, borderRect.left, borderRect.top, borderRect.left + borderRect.width, borderRect.top + borderRect.height))
    {
        dashLine.push_back(sf::RectangleShape(dashLineRect)); //增加虛線
        dashLine.back().setPosition(dashPosition);            //設定位置
        dashLine.back().setRotation(angle * 180 / PI);        //設定角度
        dashLine.back().setFillColor(color.getDarkColor());   //設定顏色
        dashPosition.x += deltaX * 2;                         // x 增加
        dashPosition.y += deltaY * 2;                         // y 增加
    }
}

bool GameObject::PulseLaser::isCollided(sf::Vector2f &point, int radius) const
{
    if (pulsing) //釋放時
    {
        const sf::Vector2f &position(line.getPosition());                                                                  //取得位置
        return distanceOfPointToLineByAngle(point.x, point.y, position.x, position.y, angle) <= radius + line.getSize().y; //點線距離
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
        else
        {
            line.setPosition(getPosition() + deltaShake * static_cast<float>(rand() % 5 - 5)); //重新定位震動
            if (line.getOutlineThickness() < thickness)                                        //如果寬度小於指定的寬度
            {
                line.setOutlineThickness(line.getOutlineThickness() + deltaThickness * deltaTime); //變寬
            }
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
