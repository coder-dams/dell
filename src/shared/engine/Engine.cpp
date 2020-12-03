#include "Engine.h"
#include <iostream>
#include <unistd.h>

using namespace state;
using namespace std;
using namespace engine;



Engine::Engine():currentState("INIT"){}

state::State &Engine::getState()
{
    state::State &refState = currentState;
    return refState;
}

void Engine::addCommand (std::unique_ptr<Command> ptr_cmd)
{
    int priority;
    if (engineCommands.size() > 0)
    {
        priority = engineCommands.rbegin()->first + 1;
    }
    else
    {
        priority = 0;
    }
    engineCommands[priority] = move(ptr_cmd);
}

void Engine::setState(state::State &nState){

    //this->currentState = &nState;
}


void Engine::init(){
    return;
}
