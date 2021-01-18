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
	int health = targetedCharacter.stats.getHealth();
	int damage = mainCharacter.getSpells().getDamage();
	int attackP = mainCharacter.stats.getActPoints();

	cout<<" \n"<< mainCharacter.name<<" is attacking "<<targetedCharacter.name<<endl;
	cout<<targetedCharacter.name <<" has "<<
	health<<"HP"<<endl;

	int newHealth=health-damage;
	targetedCharacter.stats.setHealth(newHealth);
	mainCharacter.stats.setActPoints(attackP-mainCharacter.getSpells().getCost());
	/*switch(damage) {
      case 20:
        mainCharacter.stats.setActPoints(attackP-mainCharacter.getSpells().getCost());
        break;
      case 10:
        mainCharacter.stats.setActPoints(attackP-mainCharacter.getSpells().getCost());
        break;
      case 15:
        mainCharacter.stats.setActPoints(attackP-mainCharacter.getSpells().getCost());
        break;
	}*/
	if(newHealth<=0){
		targetedCharacter.setStatus(DEAD);
	}

	cout<<targetedCharacter.name <<" now has "<<
	targetedCharacter.stats.getHealth()<<"HP \n"<<endl;

	cout<<mainCharacter.name <<" has now "<<
	mainCharacter.stats.getActPoints()<<" attack points remaining \n"<<endl;

}
