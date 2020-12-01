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
    return;
}

void Engine::setState(state::State &nState){

    return;
}

/* state::State &Engine::getState(){
    return this->currentState;
}
 */

void Engine::init(){
    return;
}
