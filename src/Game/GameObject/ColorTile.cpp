#include "Game/GameObject/ColorTile.h"

#include <iostream>

// UI Draw Function
void GameObject::ColorTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
    target.draw(pantone, states);
}

// Constructor & Deconstructor
GameObject::ColorTile::ColorTile(Point position, int &width, int &height, int &characterSize, sf::Font &font, int &points, int &radius, float &hoverScale, Color &color, std::function<void()> onClick) : Tile(position), width(width), height(height), text(Point(position.x + width / 2, position.y + characterSize / 2), characterSize, font, color.name), pantone(Point(position.x + width / 2, position.y + height - radius), points, radius, hoverScale, color, onClick)
{
    std::cout << position.x + width / 2 << ", " <<  position.y + height - radius << '\n';
    // Text
    // text.setCharacterSize(characterSize);
    // text.setFont(font);
    // text.setText(color.name);

    // Pantone
    // pantone.setPoints(points);
    // pantone.setRadius(radius);
    // pantone.setHoverScale(hoverScale);
    // pantone.setColor(color);
    // pantone.setupShape();

    // setPosition(getPosition());
}

GameObject::ColorTile::~ColorTile()
{
}

void GameObject::ColorTile::setPosition(Point &position)
{
    GameObject::setPosition(position);

    Point textPoint(position.x + width / 2, position.y + text.getGlobalBounds().height / 2);
    text.setPosition(textPoint);

    Point pantonePoint(position.x + width / 2, position.y + height - pantone.getRadius());
    pantone.setPosition(pantonePoint);
}

// Mouse Move
void GameObject::ColorTile::updateMouseMove(Point &point)
{
    pantone.updateMouseMove(point);
}

// Mouse Press
void GameObject::ColorTile::updateMousePress(Point &point)
{
    pantone.updateMousePress(point);
}

// Mouse Release
void GameObject::ColorTile::updateMouseRelease(Point &point)
{
    pantone.updateMouseRelease(point);
}
void GameObject::ColorTile::update()
{
}