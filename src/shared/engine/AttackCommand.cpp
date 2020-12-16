#include "AttackCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;

AttackCommand::AttackCommand (state::Character &mainC, state::Character &targetedC): 
mainCharacter(mainC), targetedCharacter(targetedC)
{
	return;
}


void AttackCommand::execute (state::State &state)
{
	int health = targetedCharacter.getStats().getHealth();
	int damage = mainCharacter.getSpells().getDamage();

	cout<<targetedCharacter.name <<" has "<<
	health<<"HP"<<endl;

	int newHealth=health-damage;
	targetedCharacter.getStats().setHealth(newHealth);

	cout<<targetedCharacter.name <<" now has "<<
	newHealth<<"HP"<<endl;


	return;
}
