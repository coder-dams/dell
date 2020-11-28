#include "Character.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;

/* La différence majeure entre un attribut d'une classe et les arguments dans son constructeur de base est que 
les attributs seront à reutiliser dans d'autres méthodes que le contructeur  */

Stats Character::getStats ()
{
	return this->stats;
}

Spells Character::getSpells ()
{
	return this-> spellSet;
}


TypeID Character::getType ()
{
	return this->typeID;
}

CharacterStatusID Character::getStatus () {
	return this->status;
}

void Character::setStatus(CharacterStatusID newStatus) {
	this -> status = newStatus;
}

void Character::LevelUp() {
	if (stats.experience == 100) {
		stats.level+=1;
	}
}

bool Character::isMapCell()
{
    return false;
}


Character::Character (TypeID id, std::string cName, int PosX, int PosY, int p_tileCode, Spells cSpellSet) {

spellSet = cSpellSet;
tileCode = p_tileCode;
typeID = id;
status = WANDERING;
name = cName;
position.setX(PosX);
position.setY(PosY);

	if (id == PLAYER)
		{
		stats.setHealth(150);
		stats.setMovPoints(30);
		stats.setActPoints(15);
		stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);
		}

    else if (id == BOWMAN)
    {
        stats.setHealth(80);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(THROW);
    }
	else if (id == SORCERER)
    {
        stats.setHealth(80);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(IGNITE);
    }
	else if (id == SKELETON)
    {
        stats.setHealth(100);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);
    }

}

//std::vector<Position> Character::verifMovingPosition (state::State& state) {

//}

//std::vector<int> Character::verifAttackPosition (state::State& state) {
	
//}
