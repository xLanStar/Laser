#include "Button.h"

GameObject::Button::Button(sf::Vector2f position, Color &color, sf::Font &font, std::string str, int characterSize, sf::SoundBuffer &soundBuffer, std::function<void()> onClick, float characterScaler)
    : GameObject(color, position), onClick(onClick), hover(false), pressed(false), text(position, characterSize, color, font, str), characterSize(characterSize), characterScaler(characterScaler)
{
    sound.setBuffer(soundBuffer);
}

void GameObject::Button::setColor(Color &color) // 設定顏色
{
    text.setColor(color);
}

void GameObject::Button::setPosition(sf::Vector2f point) // 設定位置
{
    GameObject::setPosition(point);
    text.setPosition(point);
}

void GameObject::Button::updateMouseMove(sf::Vector2f &point) // 滑鼠移動的觸發事件
{
    sf::FloatRect rect = text.getGlobalBounds(); // 如果被覆蓋，就 Switch 旗標
    if (rect.contains(point.x, point.y))
    {
        hover = true;
    }
    else
    {
        hover = false;
    }
}

void GameObject::Button::updateMousePress(sf::Vector2f &point) // 滑鼠按下的觸發事件
{
    if (hover) //如果被覆蓋，又被點擊，則 Switch 旗標
    {
        sound.play();
        pressed = true;
    }
}

void GameObject::Button::updateMouseRelease(sf::Vector2f &point) // 滑鼠放開的觸發事件
{
    pressed = false; // 釋放旗標
    if (hover)       //如果被覆蓋，則觸發 function
    {
        onClick();
    }
}

void GameObject::Button::update(float deltaTime) // 滑鼠更新
{
    if (hover) // 如果被 hover 字就變大
    {
        text.setCharacterSize(characterSize * characterScaler);
    }
    else
    {
        text.setCharacterSize(characterSize);
    }
}

void GameObject::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const // 渲染
{
    target.draw(text, states);
}