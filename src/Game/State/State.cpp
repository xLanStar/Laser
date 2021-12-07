#include "State.h"

#include <stack>

State::State(Setting &setting, std::stack<State *> &states) : setting(setting), states(states)
{
    quit = false;
}

State::~State()
{
    
}

// Accessors
bool State::getQuit()
{
    return quit;
}

void State::Quit()
{
    quit = true;
}
