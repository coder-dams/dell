#include "Command.h"
using namespace engine;

CommandTypeId Command::getCommandTypeId(){
	return commandTypeId;
}


void Command::execute(state::State& state){
	return;
}

