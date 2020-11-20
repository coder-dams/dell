#include "Engine.h"
#include <iostream>
#include <unistd.h>

using namespace state;
using namespace std;
using namespace engine;

Engine()
{

}

state::State &Engine::getState()
{
    state::State &refState = currentState;
    return refState;
}

void Engine::addCommand (std::unique_ptr<Command> ptr_cmd)
{

}


