#include "Character.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

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


Character::Character (TypeID id, std::string cName, int PosX, int PosY, Spells cSpellSet,int Owner,int ctileID) {

spellSet = cSpellSet;
typeID = id;
status = FIGHTING;
name = cName;
tileID=ctileID;
position.setX(PosX);
position.setY(PosY);
playerOwner=Owner;



	if (id == PLAYER)
		{
		stats.setHealth(150);
		stats.setMovPoints(5);
		stats.setActPoints(3);
		stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);


		}

    else if (id == BOWMAN)
    {
        stats.setHealth(50);
        stats.setMovPoints(3);
        stats.setActPoints(5);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(THROW);

    }
	else if (id == SORCERER)
    {
        stats.setHealth(50);
        stats.setMovPoints(2);
        stats.setActPoints(6);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(IGNITE);


    }
	else if (id == SKELETON)
    {
        stats.setHealth(100);
        stats.setMovPoints(4);
        stats.setActPoints(6);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);


    }

}

int Character::getPlayerOwner() const {
    return playerOwner;
}

int Character::getTileID() {
    return tileID;
}

/*
std::vector<Position> Character::verifMovingPosition (state::State& state) {
	
    std::vector<Position> canGoList;
    std::vector<Position> validNears;

    for (auto &nearPosition : position.nearPositions(position))
        // if within map
        if (nearPosition.getY() >= 0 && nearPosition.getX() >= 0 
        && (unsigned int)nearPosition.getX() <= state.getMap()[0].size()
        && (unsigned int)nearPosition.getY() <= state.getMap().size())
            validNears.push_back(move(nearPosition));

    for (auto &validNear : validNears)
    {
        for (auto &line : state.getMap())
        {
            if(line[0]->getPosition().getY() != validNear.getY())
                continue;
            for (auto &mapcell : line)
            {
                if(mapcell->getPosition().getX() != validNear.getX())
                    continue;
                if (mapcell->getPosition().equals(validNear) && mapcell->isOccupied(state) == -1)
                    canGoList.push_back(move(mapcell->getPosition()));
            }
        }
    }

    return canGoList;
}*/

std::vector<int> Character::verifAttackPosition (state::State& state) {
	vector<int> possibleIndexes;
    for(unsigned int i = 0; i < state.getCharacters().size(); i++){
        Character& charac = *state.getCharacters()[i];
        if(charac.getPlayerOwner() != playerOwner && charac.getStatus() != DEAD){
            // check distances
            int maxDistance = charac.getSpells().getRange() + 1;
            Position charapos = charac.getPosition();
            Position& charaposref = charapos;
            if(position.distance(position,charaposref) <= maxDistance){
                possibleIndexes.push_back(i);
            }
        }
    }
    return possibleIndexes;	
}



