#include "Game/GameObject/Text.h"

// UI Draw Function
void GameObject::Text::draw(sf::RenderTarget &target, sf::RenderStates states) const //渲染
{
    target.draw(text, states);
}

GameObject::Text::Text(sf::Vector2f position, int characterSize, Color &color, sf::Font &font, std::string str) : GameObject(position, color), font(font)
{
    text.setFont(font);
    setColor(color);
    setText(str);
    setCharacterSize(characterSize);
    setPosition(position);
}

// Accessors
sf::FloatRect GameObject::Text::getGlobalBounds() const //取得整個容器空間的
{
    return text.getGlobalBounds();
}

std::string GameObject::Text::getText() const //取得字的內容
{
    return text.getString();
}

// Functions
void GameObject::Text::setColor(Color &color) //設定顏色
{
    text.setFillColor(color.getDarkColor()); //字體顏色為深色
}

void GameObject::Text::setCharacterSize(int characterSize) //設定整個容器的長寬
{
    text.setCharacterSize(characterSize);                  //設定 text 物件的字的大小
    sf::FloatRect textRect = text.getLocalBounds();        //取得 text 物件的 bound
    text.setOrigin(textRect.left + textRect.width / 2.0f,  //設定容器的座標為中心點
                   textRect.top + textRect.height / 2.0f); //設定容器的座標為中心點
}

void GameObject::Text::setText(std::string &str) //設定文字
{
    text.setString(str);
}

void GameObject::Text::setPosition(sf::Vector2f position) //設定位置
{
    GameObject::setPosition(position);
    text.setPosition(position.x, position.y);
}