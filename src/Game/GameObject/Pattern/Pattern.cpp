#include "Pattern.h"

#include <cmath>

// Constructor
GameObject::Pattern::Pattern(Color &color, int &radius, std::string name, int boundRoundThickness)
    : GameObject(), color(color), radius(radius), name(name), boundRoundThickness(boundRoundThickness)
{
    setupShape();
}
// Getter
const std::string &GameObject::Pattern::getName() const //取得 Pattern 名稱
{
    return name;
}
// Setter
void GameObject::Pattern::setRadius(int radius) //取得 Pattern 名稱
{
    this->radius = radius;
}

void GameObject::Pattern::setPosition(sf::Vector2f &position) //設定位置
{
    // GameObject::setPosition(position);
    boundRound.setPosition(position);
}
// Public Functions
void GameObject::Pattern::updateMouseMove(sf::Vector2f &position) // Pattern 移動到玩家的位置
{
    boundRound.setPosition(position);
}

void GameObject::Pattern::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(boundRound); //外圓
}

// Private Functions
void GameObject::Pattern::setupShape()
{
    boundRound.setRadius(radius);                        //設定半徑
    boundRound.setOutlineThickness(boundRoundThickness); //設定線寬
    boundRound.setFillColor(color.getLightColor());      //內部填滿亮色
    boundRound.setOutlineColor(color.getDarkColor());    //外框深色

    sf::FloatRect rect = boundRound.getLocalBounds();
    boundRound.setOrigin(rect.left + rect.width / 2.0f,
                         rect.top + rect.height / 2.0f);
}