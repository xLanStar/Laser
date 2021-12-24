#include "Game/GameObject/Laser/NormalLaser.h"

#include <cmath>

#include "Game/Util.h"

void GameObject::NormalLaser::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(line); //渲染

    // if (showHitBox)
    // {
    //     target.draw(box);
    //     target.draw(box2);
    // }
}

GameObject::NormalLaser::NormalLaser(sf::Vector2f position, int &length, int &thickness, float &angle, float &speed, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop) : Laser(position, color, thickness, borderRect, prop), angle(angle), speed(speed), length(length)
{
    velocity = sf::Vector2f(cos(angle) * speed, sin(angle) * speed); //對不同座標的垂直速度和水平速度
    endPosition = position;                                          //尾端點
    line = sf::RectangleShape(sf::Vector2f(0, thickness));           //線物件的長寬
    line.setFillColor(color.getDarkColor());                         //線的顏色
    line.setPosition(position);                                      //設定位置
    line.setRotation(angle * 180 / PI + 180);                        //線旋轉

    // Debug Box
    // box.setSize(sf::Vector2f(16, 16));
    // box.setOrigin(8, 8);
    // box.setOutlineColor(sf::Color(255, 0, 0));
    // box.setOutlineThickness(5);
    // box.setFillColor(sf::Color(0, 0, 0, 0));

    // box2.setSize(sf::Vector2f(16, 16));
    // box2.setOrigin(8, 8);
    // box2.setOutlineColor(sf::Color(255, 0, 0));
    // box2.setOutlineThickness(5);
    // box2.setFillColor(sf::Color(0, 0, 0, 0));
}

bool GameObject::NormalLaser::isCollided(sf::Vector2f &point, int &radius) const //是否碰撞
{
    float distance = distanceOfPointToSeg(point.x, point.y, startPosition.x, startPosition.y, endPosition.x, endPosition.y); //點線距離

    return distance < radius; //回傳是否碰撞到
}

void GameObject::NormalLaser::update(float &deltaTime) //更新
{
    startPosition = line.getPosition();         //取得起點座標
    sf::Vector2f offset = velocity * deltaTime; //座標變化量
    //檢查是否在邊界內
    if (inRange(line.getPosition().x, line.getPosition().y, getBorderRect().left, getBorderRect().top, getBorderRect().left + getBorderRect().width, getBorderRect().top + getBorderRect().height))
    {
        line.move(offset);             //移動物件
        if (line.getSize().x < length) //如果線太短
        {
            line.setSize(sf::Vector2f(line.getSize().x + speed * deltaTime, getThickness())); //線就變長
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
            line.setSize(sf::Vector2f(line.getSize().x - speed * deltaTime, getThickness()));
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
    // if (showHitBox)
    // {
    //     box.setPosition(endPosition);
    //     box2.setPosition(line.getPosition());
    // }
}
void GameObject::NormalLaser::setPosition(sf::Vector2f position){

};