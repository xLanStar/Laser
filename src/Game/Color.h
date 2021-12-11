#pragma once

#include "SFML/Graphics.hpp"

class Color
{
public:
    std::string name;
    sf::Color backgroundColor;
    sf::Color darkColor;
    sf::Color lightColor;

    // Constructor & Deconstructor
    Color();
    Color(std::string name, sf::Color backgroundColor, sf::Color darkColor, sf::Color lightColor);
    ~Color();
    
};