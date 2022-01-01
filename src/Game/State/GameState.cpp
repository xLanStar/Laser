#include "Game/State/GameState.h"

#include <cmath>

#include "Game/Game.h"
#include "Game/Util.h"
#include "Game/GameObject/Laser/NormalLaser.h"
#include "Game/GameObject/Laser/PulseLaser.h"

// Initializer
void GameState::initUI()
{
    borderRect = sf::FloatRect(borderSize, borderSize, game.setting.getWindowSize().x - borderSize * 2, game.setting.getWindowSize().y - borderSize * 2);

    border.setSize(sf::Vector2f(game.setting.getWindowSize().x - borderSize * 2,
                                game.setting.getWindowSize().y - borderSize * 2));
    border.setPosition(sf::Vector2f(borderSize, borderSize));
    border.setFillColor(sf::Color(0, 0, 0, 0));
    border.setOutlineColor(game.setting.getColor().getDarkColor());
    border.setOutlineThickness(6);

    borderBackground.setSize(sf::Vector2f(game.setting.getWindowSize().x - borderSize * 2,
                                          game.setting.getWindowSize().y - borderSize * 2));
    borderBackground.setPosition(sf::Vector2f(borderSize, borderSize));
    borderBackground.setFillColor(sf::Color(0, 0, 0, 0));
    borderBackground.setOutlineColor(game.setting.getColor().getLightColor());
    borderBackground.setOutlineThickness(borderSize);
}

// UI Draw Function
void GameState::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw lasers
    for (auto &it : lasers)
    {
        target.draw(*it);
    }

    // Draw Border
    target.draw(borderBackground);
    target.draw(border);

    // Draw Text
    target.draw(mvpText);
    target.draw(scoreText);
    target.draw(difficultyText);

    // Draw lasers Particle System
    for (auto &it : lasers)
    {
        target.draw(it->getParticleSystem());
    }

    State::draw(target, states);
}

// Constructor
GameState::GameState(Game &game) : State(game), generateInterval(game.setting.getCurrentGenerateInterval()),
                                   mvpText(game.setting.getPointAtWindow(35, 4.3), 44, game.setting.getColor(), game.setting.getFont(), (std::string) "MVP : " + toString(game.setting.getCurrentHighestScore())),
                                   scoreText(game.setting.getPointAtWindow(65, 4.3), 44, game.setting.getColor(), game.setting.getFont(), (std::string) "Score : " + toString(game.setting.getCurrentScore())),
                                   difficultyText(game.setting.getPointAtWindow(50, 95.7), 47, game.setting.getColor(), game.setting.getFont(), (std::string) "Difficulty : " + game.setting.getDifficultyName())
{
    borderLeft = borderSize;
    borderTop = borderSize;
    borderRight = game.setting.getWindowSize().x - borderSize;
    borderBottom = game.setting.getWindowSize().y - borderSize;
    randomPositionWidthSize = borderRight - borderLeft;
    randomPositionHeightSize = borderBottom - borderTop;
    initUI();
}

GameState::~GameState()
{
    // Clear Lasers
    for (auto it = lasers.begin(); it != lasers.end(); it++)
    {
        lasers.erase(it);
    }
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

    if (mousePosition.x <= borderLeft + game.getCursor().getRadius() ||
        mousePosition.x >= borderRight - game.getCursor().getRadius() ||
        mousePosition.y <= borderTop + game.getCursor().getRadius() ||
        mousePosition.y >= borderBottom - game.getCursor().getRadius())
    {
        game.death();
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
        else if ((*it)->isCollided(game.getCursor()))
        {
            game.death();
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
                                                         angle,
                                                         game.setting.getColor(),
                                                         borderRect,
                                                         game.setting.getNormalLaserProp(),
                                                         game.setting.getMovingLaserVelocity()));
        }
        else
        {
            lasers.push_back(new GameObject::PulseLaser(position,
                                                        angle,
                                                        game.setting.getColor(),
                                                        borderRect,
                                                        game.setting.getNormalLaserProp()));
        }
        game.setting.increaseCurrentScore();
        std::string text = "SCORE : " + toString(game.setting.getCurrentScore());
        scoreText.setText(text);
        // std::cout << "[GameState] spwan new laser!\n";
    }
}
