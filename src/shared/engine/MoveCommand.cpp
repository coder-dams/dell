#include "MoveCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;

MoveCommand::MoveCommand(state::Character &mainCharacter, state::Position &positionTarget) : mainCharacter(mainCharacter), positionTarget(positionTarget)
{
	
}

void MoveCommand::execute(state::State &state)
{
	return;
}
