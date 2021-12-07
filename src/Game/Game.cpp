#include "Game.h"

#include <iostream>

#include "Game/State/MainMenuState.h"

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
    states.push(new MainMenuState(setting, states));
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
            states.top()->updateMouseMove(event.mouseMove.x, event.mouseMove.y);
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            states.top()->updateMousePress(event.mouseButton.x, event.mouseButton.y);
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            states.top()->updateMouseRelease(event.mouseButton.x, event.mouseButton.y);
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                states.top()->Quit();
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
        if (states.top()->getQuit())
        {
            delete states.top();
            states.pop();
            /**# Back To Second Top State
             * - update top state
             */
            if (!states.empty())
            {
                states.top()->update(deltaTime);
            }
        }
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