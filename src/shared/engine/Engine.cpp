#include "Engine.h"
#include <iostream>
#include <unistd.h>

using namespace state;
using namespace std;
using namespace engine;



Engine::Engine():currentState("INIT"){
    regist["commands"][0] = "";
    regist["leng"] = 0;
}

state::State &Engine::getState()
{
    state::State &refState = currentState;
    return refState;
}

void Engine::addCommand (std::unique_ptr<Command> cmdPtr)
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
    Json::Value nCommand = cmdPtr->toRegist();
	regist["CommandRange"][regist["Size"].asUInt()] = nCommand;
	regist["Size"] = regist["Size"].asUInt() + 1;
    engineCommands[priority] = move(cmdPtr);
}


Json::Value Engine::getRegist(){
    return regist;
}

void Engine::init(){
        cout << "Executing commands from turn " << currentState.getCurrentTurn() << endl;

        //default event
        //StateEvent stateEvent(ALLCHANGED);
        bool endTurn = false;
        for (size_t i = 0; i < engineCommands.size(); i++)
        {

            //stateEvent.setFightAction(ATTACKING);
            engineCommands[i]->execute(currentState);
            //currentState.notifyObservers(stateEvent, currentState);
            if(currentState.getMode() == "engine"){
                usleep(200 * 1000);
            }
        }
        // clean using iterator
        engineCommands.clear();

       
}
