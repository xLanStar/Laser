#include "Game/GameObject/ColorTile.h"

// UI Draw Function
void GameObject::ColorTile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(text, states);
    target.draw(pantone, states);
}

// Constructor & Deconstructor
GameObject::ColorTile::ColorTile(sf::Vector2f position, sf::Vector2f &rect, int characterSize, sf::Font &font, int points, int radius, float hoverScale, Color &color, std::function<void()> onClick) : GameObject(position, color), text(sf::Vector2f(position.x + rect.x / 2, position.y + characterSize / 2), characterSize, color, font, color.getName()), pantone(sf::Vector2f(position.x + rect.x / 2, position.y + rect.y - radius), points, radius, hoverScale, color, onClick), rect(rect)
{
}

void GameObject::ColorTile::setColor(Color &color)
{
    pantone.setColor(color);
}

void GameObject::ColorTile::setPosition(sf::Vector2f &position)
{
    GameObject::setPosition(position);

    sf::Vector2f textPoint(position.x + rect.x / 2, position.y + text.getGlobalBounds().height / 2);
    text.setPosition(textPoint);

    sf::Vector2f pantonePoint(position.x + rect.x / 2, position.y + rect.y - pantone.getRadius());
    pantone.setPosition(pantonePoint);
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