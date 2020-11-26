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
/* 	for( auto & charac : state.getCharacters()){
        if(fight.getCurrentTurn() == charac->getPlayerOwner())
            charac->setStatus(AVAILABLE);
    }
    target.setStatus(SELECTED); */
	return;
}



