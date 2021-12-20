#pragma once

#include <stack>

#include "SFML/Window.hpp"

#include "Game/State/State.h"
#include "Game/Setting.h"

extern bool showHitBox;
extern bool invincible;

enum StateType //列舉狀態
{
    MAINMENU = 0,
    EXIT,
    SETTING,
    COLOR,
    PATTERN,
    GAME,
    DIFFICULTY,
    REPLAY
};

class Game
{
private:
    // Variables
    // SFML Window
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Cursor
    sf::Vector2f currentMousePosition;
    GameObject::Pattern *cursor;

    // States
    StateType currentStateType;
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

    // Accessors
    void setColorTheme(std::string colorTheme);
    void setCursor(std::string name);
    sf::Vector2f &getMousePosition();
    // sf::Vector2u &getWindowSize();
    // sf::FloatRect &getLaserBorderRect();

    // Functions
    // push new state on top
    void pushState(StateType stateType);
    // pop top state
    void popState();
    // pop and push
    void switchState(StateType stateType);
    // GameOver when player fail, only in GAME stateType can use death()
    void death();

    // update functions
    void updateDeltaTime();
    void updateEvents();
    void update();

    // render functions
    void render();

    // Core
    void run();
    void stop();
};