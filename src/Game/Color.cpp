#include "Game/Color.h"

const void Color::operator=(Color other)
{
    name = other.name;
    darkColor = other.getDarkColor();
    lightColor = other.getLightColor();
}

Color::Color()
{
}

Color::Color(std::string name, sf::Color darkColor, sf::Color lightColor) : name(name), darkColor(darkColor), lightColor(lightColor)
{
}

Color::~Color()
{
}

std::string &Color::getName()
{
    return name;
}

sf::Color &Color::getDarkColor()
{
    return darkColor;
}

sf::Color &Color::getLightColor()
{
    return lightColor;
}