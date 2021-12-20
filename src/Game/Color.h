#pragma once

#include "SFML/Graphics.hpp"
//使用 sf::color 複合而成的顏色結構
class Color
{
private:
    std::string name;     //顏色組合名稱
    sf::Color darkColor;  //暗色
    sf::Color lightColor; //亮色

public:
    // Constructor & Deconstructor
    Color();
    Color(std::string name, sf::Color darkColor, sf::Color lightColor);
    ~Color();

    // Accessors
    std::string &getName();     //取得顏色的名稱
    sf::Color &getDarkColor();  //取的暗色
    sf::Color &getLightColor(); //取得亮色

    const void operator=(Color other); //覆寫 =
};