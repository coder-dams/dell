#include "SelectCharacterCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;

SelectCharacterCommand::SelectCharacterCommand (state::Character &pselectedCharacter): selectedCharacter(pselectedCharacter)
{
	return;
}



void SelectCharacterCommand::execute(state::State &state)
{
	return;
}



