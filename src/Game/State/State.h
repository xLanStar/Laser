#pragma once

#include "Game/GameObject/GameObject.h"

class Game;

class State : public sf::Drawable //可繪的
{
private:
protected:
public:
    // Reference
    Game &game;

    // UI
    const int borderSize = 8;
    sf::RectangleShape border;
    std::map<std::string, GameObject::GameObject *> gameObjects; //模式文字對應到模式物件

    // Constructor
    State(Game &game);
    ~State();

    // Functions
    virtual void Quit();

    // Virtual Functions
    virtual void setColor(Color &color);                  //設定顏色
    virtual void updateMouseMove(sf::Vector2f &point);    //滑鼠移動
    virtual void updateMousePress(sf::Vector2f &point);   //滑鼠按下
    virtual void updateMouseRelease(sf::Vector2f &point); //滑鼠釋放
    virtual void update(float &deltaTime);                //更新

    // UI Draw Function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染
};