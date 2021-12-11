#pragma once

#include <stack>

#include "SFML/Window.hpp"

#include "Game/State/State.h"
#include "Game/Setting.h"

enum StateType
{
    MAINMENU = 0,
    EXIT,
    SETTING,
    COLOR,
    PATTERN,
    GAME
};

class Game
{
private:
    // Variables
    // SFML Window
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    // States
    std::stack<State *> states;

    // Update & Render Values
    sf::Clock deltaTimeClock;
    float deltaTime;

    // Initializer
    void initWindow();
    void initState();

public:
    // Setting
    Setting setting;

    // Constructor
    Game();
    ~Game();

    // Accessor

    // push new state on top
    void pushState(StateType stateType);
    // back to 2nd state
    void popState();

    // Functions
    void updateDeltaTime();
    void updateEvents();
    void update();
    void render();

    // Core
    void run();
    void stop();
};