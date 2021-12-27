#include "Game.h"

#include <iostream>

#include "Game/State/MainMenuState.h"
#include "Game/State/SettingState.h"
#include "Game/State/ColorState.h"
#include "Game/State/PatternState.h"
#include "Game/State/ExitState.h"
#include "Game/State/DifficultyState.h"
#include "Game/State/GameState.h"
#include "Game/State/ReplayState.h"

bool showHitBox = true; //顯示碰撞箱
bool invincible = true; //無敵

// Initializer
void Game::initWindow()
{
    videoMode.width = setting.getWindowSize().x;
    videoMode.height = setting.getWindowSize().y;

    window = new sf::RenderWindow(videoMode, "Laser", sf::Style::Titlebar | sf::Style::Close);

    window->setMouseCursorVisible(false);

    window->setFramerateLimit(60);
}

void Game::initState()
{
    pushState(MAINMENU);
}

// Constructor
Game::Game() : setting()
{
    cursor = setting.findCursor("Round");
    cursor->setColor(setting.getColor());
    initWindow();
    initState();
}

// Deconstructor
Game::~Game()
{
    delete window;

    while (!states.empty())
    {
        delete &states.top();
        states.pop();
    }
}

const GameObject::Pattern &Game::getCursor() const
{
    return *cursor;
}
// Accessors
void Game::setColorTheme(std::string colorTheme)
{
    setting.setColorTheme(colorTheme);
    cursor->setColor(setting.getColor());
    states.top()->setColor(setting.getColor());
}

void Game::setCursor(std::string name)
{
    cursor = setting.findCursor(name);
    cursor->setColor(setting.getColor());
    sf::Vector2f mousePosition = getMousePosition();
    cursor->setPosition(mousePosition);
}

sf::Vector2f &Game::getMousePosition()
{
    return currentMousePosition;
}

void Game::death()
{
    if (currentStateType == GAME)
    {
        setting.saveCurrentScore();
        switchState(REPLAY);
    }
}

// State Controller
// Push New State On Top
void Game::pushState(StateType stateType)
{
    currentStateType = stateType;
    switch (stateType)
    {
    case MAINMENU:
        states.push(new MainMenuState(*this));
        break;
    case EXIT:
        states.push(new ExitState(*this));
        break;
    case SETTING:
        states.push(new SettingState(*this));
        break;
    case COLOR:
        states.push(new ColorState(*this));
        break;
    case PATTERN:
        states.push(new PatternState(*this));
        break;
    case DIFFICULTY:
        states.push(new DifficultyState(*this));
        break;
    case GAME:
        states.push(new GameState(*this));
        break;
    case REPLAY:
        states.push(new ReplayState(*this));
        break;
    }
}

// Pop Top State
void Game::popState()
{
    if (states.size() != 0)
    {
        states.pop();
        if (!states.empty())
        {
            states.top()->setColor(setting.getColor());
        }
    }
}

// Switch State
void Game::switchState(StateType stateType)
{
    if (states.size() != 0)
    {
        states.pop();
    }

    pushState(stateType);
}

// Update DeltaTime
void Game::updateDeltaTime()
{
    deltaTime = deltaTimeClock.restart().asSeconds();
}

// Update Events
void Game::updateEvents()
{
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::MouseMoved)
        {
            currentMousePosition.x = event.mouseMove.x;
            currentMousePosition.y = event.mouseMove.y;
            states.top()->updateMouseMove(currentMousePosition);
            cursor->updateMouseMove(currentMousePosition);
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            states.top()->updateMousePress(currentMousePosition);
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            states.top()->updateMouseRelease(currentMousePosition);
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                states.top()->Quit();
            }
            /**
             * DEBUG
             */
            else if (event.key.control && event.key.code == sf::Keyboard::A)
            {
                showHitBox = !showHitBox;
                std::cout << "[Game] set ShowHitBox to " << showHitBox << '\n';
            }
            else if (event.key.control && event.key.code == sf::Keyboard::S)
            {
                invincible = !invincible;
                std::cout << "[Game] set invincible to " << invincible << '\n';
            }
            else if (event.key.control && event.key.code == sf::Keyboard::D)
            {
                setting.debugParticleSystem1();
                std::cout << "[Game] NormalLaserProp debug" << '\n';
            }
        }
        else if (event.type == sf::Event::Resized)
        {
            setting.setWindowSize(window->getSize());
            std::cout << "[Game] Resize Window to (" << setting.getWindowSize().x << ", " << setting.getWindowSize().y << ")\n";
        }
        else if (event.type == sf::Event::Closed)
        {
            stop();
            break;
        }
    }
}

// Update
void Game::update()
{
    /**
     * - update deltaTime
     * - update evnets
     * - update states
     **/
    updateDeltaTime();

    updateEvents();

    if (!states.empty())
    {
        states.top()->update(deltaTime);
    }
    else
    {
        stop();
    }
}

// Render
void Game::render()
{
    /**
     * - clear old frame
     * - render state
     * - render cursor
     * - display frame
     **/
    // window->clear(setting.getColor().backgroundColor);
    window->clear(setting.getColor().getLightColor());

    if (!states.empty())
    {
        window->draw(*states.top());
    }

    window->draw(*cursor);

    window->display();
}

// Run
void Game::run()
{
    while (window->isOpen())
    {
        update();
        render();
    }
}

// Stop
void Game::stop()
{
    setting.save();
    window->close();
}
