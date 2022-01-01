#include "Game/GameObject/Pattern/Round.h"

GameObject::Round::Round(Color &color, std::string name) : Pattern(color, name)
{
    setupShape();
}

void GameObject::Round::setupShape() //設定形狀
{
    round.setRadius(radius * 0.6);
    round.setOutlineThickness(5);
    round.setFillColor(color.getLightColor());
    round.setOutlineColor(color.getDarkColor());
    sf::FloatRect rect = round.getLocalBounds();
    round.setOrigin(rect.left + rect.width / 2.0f,
                    rect.top + rect.height / 2.0f);
}

void GameObject::Round::setColor(Color &color) //設定顏色
{
    Pattern::setColor(color);
    round.setFillColor(color.getLightColor());
    round.setOutlineColor(color.getDarkColor());
}

void GameObject::Round::setPosition(sf::Vector2f point) //設定位置
{
    Pattern::setPosition(point);
    round.setPosition(point);
}

void GameObject::Round::updateMouseMove(sf::Vector2f &position) //滑鼠移動的觸發事件
{
    Pattern::updateMouseMove(position);
    round.setPosition(position);
}

void GameObject::Round::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    Pattern::draw(target, states);
    target.draw(round);
}