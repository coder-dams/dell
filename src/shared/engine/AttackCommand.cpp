#include "AttackCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;

AttackCommand::AttackCommand (state::Character &mainC, state::Character &targetedC): mainCharacter(mainC), targetedCharacter(targetedC)
{
	return;
}


void AttackCommand::execute (state::State &state)
{
	return;
}
