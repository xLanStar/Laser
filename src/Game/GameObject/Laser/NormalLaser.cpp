#include "Game/GameObject/Laser/NormalLaser.h"

#include <cmath>

#include "Game/Util.h"

void GameObject::NormalLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(line); //渲染
}

GameObject::NormalLaser::NormalLaser(sf::Vector2f position, float arc, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int speed, int length, int thickness) : Laser(position, color, thickness, arc, borderRect, prop), speed(speed), length(length), endPosition(position), startPosition(position)
{
    velocity = sf::Vector2f(cos(arc) * speed, sin(arc) * speed); //計算速度在兩座標軸的分量
    line = sf::RectangleShape(sf::Vector2f(0, thickness));       //線物件的長寬
    line.setFillColor(color.getDarkColor());                     //線的顏色
    line.setPosition(position);                                  //設定位置
    line.setRotation(arcToDeg(arc) + 180);                       //線旋轉
}

bool GameObject::NormalLaser::isCollided(const Pattern &player) const //是否碰撞
{
    const sf::Vector2f &position = player.getPosition();                                                                           //取得玩家的圓心位置
    float distance = distanceOfPointToSeg(position.x, position.y, startPosition.x, startPosition.y, endPosition.x, endPosition.y); //計算圓心到線段的距離
    return distance <= player.getRadius();                                                                                         //回傳是否碰撞到
}

void GameObject::NormalLaser::update(float deltaTime) //更新
{
    startPosition = line.getPosition();         //取得起點座標
    sf::Vector2f offset = velocity * deltaTime; //座標變化量
    //檢查是否在邊界內
    if (inRange(borderRect, line.getPosition()))
    {
        line.move(offset);             //移動物件
        if (line.getSize().x < length) //如果線太短
        {
            line.setSize(sf::Vector2f(line.getSize().x + speed * deltaTime, thickness)); //線就變長
        }
        else
        {
            endPosition += offset; //尾端也要位移
        }
    }
    else //碰到邊界了
    {
        if (line.getSize().x > 0) //讓線變短直到長度小於 0
        {
            line.setSize(sf::Vector2f(line.getSize().x - speed * deltaTime, thickness));
            endPosition += offset;

            if (!particleSystem.isActive()) //如果粒子效果還沒啟動
            {
                particleSystem.setPosition(line.getPosition());
                particleSystem.Emit();
            }
        }
        else //線長小於 0，代表可刪除
        {
            if (particleSystem.isEmitting()) //如果粒子系統還正在發射
            {
                particleSystem.stopEmitting(); //停止粒子系統發射
            }
            else if (!particleSystem.isAlive()) //如果粒子效果結束了
            {
                destroy(); //刪除
            }
        }
    }
    particleSystem.update(deltaTime); //更新粒子效果
}