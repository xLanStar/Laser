#include "Game/GameObject/ColorTile.h"

void GameObject::ColorTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
    target.draw(pantone, states);
}

GameObject::ColorTile::ColorTile(sf::Vector2f position, sf::Font &font, Color &color, std::function<void()> onClick, int tileWidth, int tileHeight) : GameObject(color, position), text(position, 48, color, font, color.getName()), pantone(position, color, onClick), tileWidth(tileWidth), tileHeight(tileHeight)
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

void GameObject::ColorTile::updateMouseMove(sf::Vector2f &point)
{
    pantone.updateMouseMove(point);
}

void GameObject::ColorTile::updateMousePress(sf::Vector2f &point)
{
    pantone.updateMousePress(point);
}

void GameObject::ColorTile::updateMouseRelease(sf::Vector2f &point)
{
    pantone.updateMouseRelease(point);
}