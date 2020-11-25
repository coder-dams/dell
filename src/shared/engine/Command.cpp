#include "Command.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;


CommandTypeId Command::getCommandTypeId (){

    return commandTypeId;
}

void Command::execute (state::State& state){

        return;
}