#include "Game/GameObject/Laser/NormalLaser.h"

#include <cmath>

#include "Game/Util.h"

void GameObject::NormalLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(line); //渲染
}

GameObject::NormalLaser::NormalLaser(sf::Vector2f position, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int speed, int length, int thickness) : Laser(position, color, thickness, angle, borderRect, prop), speed(speed), length(length)
{
    velocity = sf::Vector2f(cos(angle) * speed, sin(angle) * speed); //對不同座標的垂直速度和水平速度
    endPosition = position;                                          //尾端點
    line = sf::RectangleShape(sf::Vector2f(0, thickness));           //線物件的長寬
    line.setFillColor(color.getDarkColor());                         //線的顏色
    line.setPosition(position);                                      //設定位置
    line.setRotation(angle * 180 / PI + 180);                        //線旋轉
}

bool GameObject::NormalLaser::isCollided(const Pattern &player) const //是否碰撞
{
    const sf::Vector2f &position = player.getPosition();
    float distance = distanceOfPointToSeg(position.x, position.y, startPosition.x, startPosition.y, endPosition.x, endPosition.y); //點線距離
    return distance <= player.getRadius();                                                                                         //回傳是否碰撞到
}

void GameObject::NormalLaser::update(float deltaTime) //更新
{
    startPosition = line.getPosition();         //取得起點座標
    sf::Vector2f offset = velocity * deltaTime; //座標變化量
    //檢查是否在邊界內
    if (inRange(borderRect,line.getPosition()))
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

            if (!getParticleSystem().isActive()) //如果粒子效果還沒結束
            {
                getParticleSystem().Emit(line.getPosition());
            }
        }
        else //線長小於 0，代表可刪除
        {
            if (getParticleSystem().isEmitting())
            {
                getParticleSystem().stopEmitting();
            }
            else if (!getParticleSystem().isAlive()) //如果粒子效果結束了
            {
                destroy(); //刪除
            }
        }
    }
    getParticleSystem().update(deltaTime); //更新粒子效果
}