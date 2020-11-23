#include "Character.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;


Stats& Character::getStats ()
{
	return stats;
}

std::vector<Spells> Character::getSpells ()
{
	return spells;
}

TypeID Character::getType ()
{
	return typeID;
}

CharacterStatusID Character::getStatus () {
	return status;
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


Character::Character (TypeID id, std::string name, int PosX, int PosY, int p_tileCode, std::vector<Spells> mySpells) {

spells = mySpells;
tileCode = p_tileCode;
typeID = id;
status = WANDERING;
// Pour le name dans élement, change donc le "name" de ce contructeur en par exemple nom 
position.setX(PosX);
position.setY(PosY);

	if (id == PLAYER)
		{
			stats.setHealth(150);
			stats.setMovPoints(30);
			stats.setActPoints(15);
			stats.setExperience(0);
			stats.setLevel(1);
		}

    else if (id == BOWMAN)
    {
        stats.setHealth(80);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
    }
	else if (id == SORCERER)
    {
        stats.setHealth(80);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
    }
	else if (id == SKELETON)
    {
        stats.setHealth(100);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
    }

}

std::vector<Position> Character::verifMovingPosition (state::State& state) {

}
std::vector<int> Character::verifAttackPosition (state::State& state) {
	
}