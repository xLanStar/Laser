#pragma once

#include <string>

#include "SFML/Graphics/Color.hpp"
//使用 sf::color 複合而成的顏色結構
class Color
{

public:
    // Constructor & Deconstructor
    Color();
    Color(std::string name, sf::Color darkColor, sf::Color lightColor);
    ~Color();

    // Accessors
    const std::string getName() const;      //取得顏色的名稱
    const sf::Color &getDarkColor() const;  //取的暗色
    const sf::Color &getLightColor() const; //取得亮色

private:
    std::string name;     //顏色組合名稱
    sf::Color darkColor;  //暗色
    sf::Color lightColor; //亮色
};