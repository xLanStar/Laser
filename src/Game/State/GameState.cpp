#include "Game/State/GameState.h"

#include <iostream>
#include <cmath>

#include "SFML/Graphics.hpp"

#include "Game/Game.h"
#include "Game/Util.h"
#include "Game/GameObject/Laser/NormalLaser.h"
#include "Game/GameObject/Laser/DashLaser.h"
#include "Game/GameObject/Laser/PulseLaser.h"

//Initializer
void GameState::initUI()
{
    border.setSize(sf::Vector2f(game.setting.getWindowSize().x - game.setting.getLaserBorderSize() * 2,
                                game.setting.getWindowSize().y - game.setting.getLaserBorderSize() * 2));
    border.setPosition(sf::Vector2f(game.setting.getLaserBorderSize(), game.setting.getLaserBorderSize()));
    border.setFillColor(sf::Color(0, 0, 0, 0));
    border.setOutlineColor(game.setting.getColor().getDarkColor());
    border.setOutlineThickness(10);
}

// Private Functions
void GameState::death()
{
    // TODO: Death Animation
    game.setting.saveCurrentScore();
    game.switchState(REPLAY);
}
// UI Draw Function
void GameState::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw lasers
    for (auto it : lasers)
    {
        target.draw(*it);
    }

    // Draw Border
    target.draw(border);

    // Draw Particle

    // Draw Text
    target.draw(mvpText);
    target.draw(scoreText);
}

//Constructor
GameState::GameState(Game &game) : State(game), generateInterval(game.setting.getCurrentGenerateInterval()), mvpText(game.setting.getPointAtWindow(30, 5), game.setting.getSubTitleCharacterSize(), game.setting.getColor(), game.setting.getFont(), (std::string) "MVP:" + toString(game.setting.getCurrentHighestScore())), scoreText(game.setting.getPointAtWindow(70, 5), game.setting.getSubTitleCharacterSize(), game.setting.getColor(), game.setting.getFont(), (std::string) "SCORE:" + toString(game.setting.getCurrentScore()))
{
    borderLeft = game.setting.getLaserBorderSize();
    borderTop = game.setting.getLaserBorderSize();
    borderRight = game.setting.getWindowSize().x - game.setting.getLaserBorderSize();
    borderBottom = game.setting.getWindowSize().y - game.setting.getLaserBorderSize();
    randomPositionWidthSize = borderRight - borderLeft;
    randomPositionHeightSize = borderBottom - borderTop;
    initUI();
}

GameState::~GameState()
{
}

// Update Functions
void GameState::updateMouseMove(sf::Vector2f &point)
{
    for (auto laser : lasers)
    {
        laser->updateMouseMove(point);
    }
}

void GameState::updateMousePress(sf::Vector2f &point)
{
    for (auto laser : lasers)
    {
        laser->updateMousePress(point);
    }
}

void GameState::updateMouseRelease(sf::Vector2f &point)
{
    for (auto laser : lasers)
    {
        laser->updateMouseRelease(point);
    }
}

void GameState::update(float &deltaTime)
{
    // Check For Border Collide
    sf::Vector2f &mousePosition(game.getMousePosition());
    if (mousePosition.x <= borderLeft + game.setting.getCursorSize() ||
        mousePosition.x >= borderRight - game.setting.getCursorSize() ||
        mousePosition.y <= borderTop + game.setting.getCursorSize() ||
        mousePosition.y >= borderBottom - game.setting.getCursorSize())
    {
        death();
        return;
    }

    // Update Lasers
    for (auto it = lasers.begin(); it != lasers.end();)
    {
        (*it)->update(deltaTime);
        if ((*it)->isDestroyed())
        {
            it = lasers.erase(it);
        }
        else if (!invincible && (*it)->isCollided(game.getMousePosition(), game.setting.getCursorSize()))
        {
            std::cout << "collided!\n";
            death();
            return;
        }
        else
        {
            it++;
        }
    }

    // Laser Generator
    counter += deltaTime;
    if (counter >= generateInterval)
    {
        counter -= generateInterval;

        // random position
        sf::Vector2f position(0, 0);
        int randSide = rand() % 4;
        if (randSide & 1)
        {
            position.x = rand() % randomPositionWidthSize + borderLeft;
            if (randSide == 1)
            {
                // 1 - bottom
                position.y = borderBottom;
            }
            else
            {
                // 3 - top
                position.y = borderTop;
            }
        }
        else
        {
            position.y = rand() % randomPositionHeightSize + borderTop;
            if (randSide == 2)
            {
                // 2 - right
                position.x = borderRight;
            }
            else
            {
                // 4 - left
                position.x = borderLeft;
            }
        }

        // calculate angle
        float angle = atan2(game.getMousePosition().y - position.y, game.getMousePosition().x - position.x);

        // random laser type
        int random = rand() % 25;
        if (random < 18)
        {
            lasers.push_back(new GameObject::NormalLaser(position,
                                                         game.setting.getNormalLaserLength(),
                                                         game.setting.getNormalLaserThickness(),
                                                         angle,
                                                         game.setting.getMovingLaserVelocity(),
                                                         game.setting.getColor(),
                                                         game.setting.getLaserBorderRect()));
        }
        else
        {
            lasers.push_back(new GameObject::PulseLaser(position,
                                                        game.setting.getPulseLaserThickness(),
                                                        angle,
                                                        game.setting.getPulseLaserDelay(),
                                                        game.setting.getPulseLaserDuration(),
                                                        game.setting.getDashLineLength(),
                                                        game.setting.getDashLineThickness(),
                                                        game.setting.getColor(),
                                                        game.setting.getLaserBorderRect()));
        }
        game.setting.increaseCurrentScore();
        std::string text = "SCORE:" + toString(game.setting.getCurrentScore());
        scoreText.setText(text);
        std::cout << "spwan\n";
    }
}
