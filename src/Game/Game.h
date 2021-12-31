#pragma once

#include <stack>

#include "Game/State/State.h"
#include "Game/Setting.h"

enum StateType //列舉狀態
{
    MAINMENU = 0,
    EXIT,
    SETTING,
    COLOR,
    PATTERN,
    GAME,
    DIFFICULTY,
    REPLAY,
    PRODUCER
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
    sf::Vector2f currentMousePosition; //現在鼠標的位置
    GameObject::Pattern *cursor;       //鼠標

    // States
    StateType currentStateType; //現在的狀態
    std::stack<State *> states; //狀態堆疊

    // Update & Render Values
    sf::Clock deltaTimeClock;
    float deltaTime;

    // Initializer
    void initWindow(); //初始化視窗
    void initState();  //初始化狀態

public:
    // Setting
    Setting setting; //設定

    // Constructor
    Game();
    ~Game();

    // Accessors
    const GameObject::Pattern &getCursor() const;
    void setColorTheme(std::string colorTheme); //設定顏色主題
    void setCursor(std::string name);           //設定鼠標者
    sf::Vector2f &getMousePosition();           //取得滑鼠位置
    // sf::Vector2u &getWindowSize();
    // sf::FloatRect &getLaserBorderRect();

    // Functions
    // push new state on top
    void pushState(StateType stateType);
    // pop top state
    void popState();
    // pop and push
    void switchState(StateType stateType); //切換狀態
    // GameOver when player fail, only in GAME stateType can use death()
    void death(); //死亡

    // update functions
    void updateDeltaTime(); //更新時間
    void updateEvents();    //更新事件
    void update();          //更新

    // render functions
    void render(); //渲染

    // Core
    void run();  //運行
    void stop(); //停止
};