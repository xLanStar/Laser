#include "Game.h"

#include <iostream>

#include "Game/State/MainMenuState.h"
#include "Game/State/SettingState.h"
#include "Game/State/ColorState.h"
#include "Game/State/PatternState.h"
#include "Game/State/ExitState.h"

// Initializer
void Game::initWindow()
{
    videoMode.width = 1280;
    videoMode.height = 720;

    window = new sf::RenderWindow(videoMode, "Laser", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(60);
}

void Game::initState()
{
    pushState(MAINMENU);
}

// Constructor
Game::Game()
{
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

// State Controller
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
    }
}

void Game::popState()
{
    if (states.size() != 0)
    {
        states.pop();
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
            Point point(event.mouseMove.x, event.mouseMove.y);
            states.top()->updateMouseMove(point);
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            Point point(event.mouseButton.x, event.mouseButton.y);
            states.top()->updateMousePress(point);
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            Point point(event.mouseButton.x, event.mouseButton.y);
            states.top()->updateMouseRelease(point);
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
                //setting.
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
     * - render objects
     * - display frame 
    **/
    //window->clear(setting.getColor().backgroundColor);
    window->clear(setting.getColor().lightColor);

    if (!states.empty())
    {
        window->draw(*states.top());
    }

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
