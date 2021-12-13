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

bool debugged = true;

// Initializer
void Game::initWindow()
{
    videoMode.width = setting.getWindowWidth();
    videoMode.height = setting.getWindowHeight();

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
    cursor = setting.getCursor();
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

// Accessors
void Game::setColorTheme(std::string colorTheme)
{
    setting.setColorTheme(colorTheme);
    cursor->setColor(setting.getColor());
    states.top()->setColor(setting.getColor());
}

void Game::setCursor(std::string name)
{
    setting.setCursor(name);
    cursor = setting.getCursor();
    cursor->setColor(setting.getColor());
    sf::Vector2f mousePosition = getMousePosition();
    cursor->setPosition(mousePosition);
}

sf::Vector2f &Game::getMousePosition()
{
    return currentMousePosition;
}

// State Controller
// Push New State On Top
void Game::pushState(StateType stateType)
{
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
        if(!states.empty())
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
        pushState(stateType);
    }
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
            else if(event.key.control && event.key.code == sf::Keyboard::A)
            {
                debugged = !debugged;
                std::cout << "[Game] set debugged to " << debugged << '\n';
            }
        }
        else if (event.type == sf::Event::Closed)
        {
            window->close();
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
        window->close();
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
    //window->clear(setting.getColor().backgroundColor);
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
    window->close();
}
