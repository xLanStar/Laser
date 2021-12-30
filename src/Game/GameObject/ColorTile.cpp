#include "Game/GameObject/ColorTile.h"

// UI Draw Function
void GameObject::ColorTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
    target.draw(pantone, states);
}

// Constructor & Deconstructor
GameObject::ColorTile::ColorTile(sf::Vector2f position, sf::Font &font, Color &color, std::function<void()> onClick, int tileWidth, int tileHeight) : GameObject(position, color), text(position, 48, color, font, color.getName()), pantone(position, color, onClick), tileWidth(tileWidth), tileHeight(tileHeight)
{
    setPosition(position);
}

void GameObject::ColorTile::setColor(Color &color)
{
    pantone.setColor(color);
}

void GameObject::ColorTile::setPosition(sf::Vector2f position)
{
    GameObject::setPosition(position);

    text.setPosition(sf::Vector2f(position.x + tileWidth / 2, position.y + text.getGlobalBounds().height / 2));

    pantone.setPosition(sf::Vector2f(position.x + tileWidth / 2, position.y + text.getGlobalBounds().height + pantone.getRadius()));
}

// Mouse Move
void GameObject::ColorTile::updateMouseMove(sf::Vector2f &point)
{
    pantone.updateMouseMove(point);
}

// Mouse Press
void GameObject::ColorTile::updateMousePress(sf::Vector2f &point)
{
    pantone.updateMousePress(point);
}

// Mouse Release
void GameObject::ColorTile::updateMouseRelease(sf::Vector2f &point)
{
    pantone.updateMouseRelease(point);
}