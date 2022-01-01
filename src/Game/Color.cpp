#include "Game/Color.h"

Color::Color()
{
    name = "Pink";
    lightColor = sf::Color(255, 202, 225);
    darkColor = sf::Color(255, 138, 188);
}

Color::Color(std::string name, sf::Color darkColor, sf::Color lightColor) : name(name), darkColor(darkColor), lightColor(lightColor)
{
}

const std::string Color::getName() const
{
    return name;
}

const sf::Color &Color::getDarkColor() const
{
    return darkColor;
}

const sf::Color &Color::getLightColor() const
{
    return lightColor;
}