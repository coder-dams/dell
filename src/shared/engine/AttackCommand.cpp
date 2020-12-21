#include "AttackCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;

AttackCommand::AttackCommand (state::Character &mChar, state::Character &tCharacter): 
mainCharacter(mChar), targetedCharacter(tCharacter)
{
	cID=ATTACK;
}

Json::Value AttackCommand::toRegist (){
    Json::Value nCommand;
	nCommand["id"] = cID;
	nCommand["player"] = mainCharacter.getPlayerOwner();
	nCommand["attacker"] = mainCharacter.name;
	nCommand["target"] = targetedCharacter.name;

	
	return nCommand;
    
}


void AttackCommand::execute (state::State &state)
{
	int health = targetedCharacter.getStats().getHealth();
	int damage = mainCharacter.getSpells().getDamage();

	cout<<targetedCharacter.name <<" has "<<
	health<<"HP"<<endl;

	int newHealth=health-damage;
	targetedCharacter.stats.setHealth(newHealth);

	cout<<targetedCharacter.name <<" now has "<<
	targetedCharacter.stats.getHealth()<<"HP"<<endl;


	return;
}
