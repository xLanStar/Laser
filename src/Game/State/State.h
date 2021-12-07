#pragma once

#include <stack>

#include <SFML/Graphics.hpp>

#include "Game/Setting.h"
#include "Game/State/State.h"

/**
 * Member-Function to void Pointer
 */
template<typename T, typename R>
void* voidCast(R(T::*f)())
{
    union
    {
        R(T::*pf)();
        void* p;
    };
    pf = f;
    return p;
}

class State : public sf::Drawable
{
private:
    // Variables
    bool quit;

    // UI Draw Function
protected:
public:
    Setting &setting;
    std::stack<State *> &states;

    // Constructor
    State(Setting &setting, std::stack<State *> &states);
    virtual ~State();

    // Accessors
    bool getQuit();
    virtual void Quit();

    // Virtual Functions
    virtual void updateMouseMove(int x, int y) = 0;
    virtual void updateMousePress(int x, int y) = 0;
    virtual void updateMouseRelease(int x, int y) = 0;
    virtual void update(float deltaTime) = 0;
    // virtual void render() = 0;
};