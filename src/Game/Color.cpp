#include "Game/Color.h"

Color::Color()
{

}

Color::Color(std::string name, sf::Color backgroundColor, sf::Color darkColor, sf::Color lightColor) : name(name), backgroundColor(backgroundColor), darkColor(darkColor), lightColor(lightColor)
{

}


Color::~Color()
{

}