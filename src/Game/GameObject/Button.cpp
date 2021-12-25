#include "Button.h"

// UI Draw Function
void GameObject::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(text, states);
}

// Constructor
GameObject::Button::Button(sf::Vector2f position, int characterSize, int hoverCharacterSize, Color &color, sf::Font &font, std::string str, std::function<void()> onClick)
    : GameObject(position, color), onClick(onClick), pressed(false), text(position, characterSize, color, font, str), characterSize(characterSize), hoverCharacterSize(hoverCharacterSize)
{
}

void GameObject::Button::setColor(Color &color)
{
    text.setColor(color);
}

void GameObject::Button::setPosition(sf::Vector2f &point)
{
    GameObject::setPosition(point);
    text.setPosition(point);
}

// Mouse Move
void GameObject::Button::updateMouseMove(sf::Vector2f &point)
{
    sf::FloatRect rect = text.getGlobalBounds();
    if (rect.contains(point.x, point.y)) //如果被覆蓋
    {
        hover = true;
    }
    else
    {
        hover = false;
    }
}

// Mouse Press
void GameObject::Button::updateMousePress(sf::Vector2f &point)
{
    if (hover)
    {
        pressed = true;
    }
}

// Mouse Release
void GameObject::Button::updateMouseRelease(sf::Vector2f &point)
{
    pressed = false;
    if (hover)
    {
        onClick();
    }
}
void GameObject::Button::update(float deltaTime)
{
    if (hover) //如果被 hover 字就變大
    {
        text.setCharacterSize(hoverCharacterSize);
    }
    else
    {
        text.setCharacterSize(characterSize);
    }
}