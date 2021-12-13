#pragma once

#include "SFML/Graphics.hpp"

class Color
{
private:
    std::string name;
    sf::Color darkColor;
    sf::Color lightColor;
    
public:
    // Constructor & Deconstructor
    Color();
    Color(std::string name, sf::Color darkColor, sf::Color lightColor);
    ~Color();
    
    // Accessors
    std::string &getName();
    sf::Color &getDarkColor();
    sf::Color &getLightColor();
    
    const void operator=(Color other);
};