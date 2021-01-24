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
		stats.setHealth(500);
		stats.setMovPoints(5);
		stats.setActPoints(3);
		stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);


		}

    else if (id == BOWMAN)
    {
        stats.setHealth(250);
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


std::vector<Position> Character::verifMovingPosition (state::State& state) {
	
    std::vector<int> map=state.getMap();
    std::vector<int> invalidMap2 ={16,38,18,19,173,174,175};
    std::vector<int> invalidMap1 ={268,223,222,177,178,199,200,181,182,203,204,176,196,194,197,238,239,215,216,217,195,237};
    std::vector<Position> validPos;
    std::vector<Position> validNears;

    for (auto &nearPosition : position.nearPositions(position)) {
        if ((nearPosition.getY() >= 0 && nearPosition.getX() >= 0 
        && (unsigned int)nearPosition.getX() <= 30
        && (unsigned int)nearPosition.getY() <= 30)){
            validNears.push_back(move(nearPosition));
        }
    }
    for (auto &validNear : validNears)
    {
        int posForMap=validNear.getX()*30+validNear.getY();
        if(std::count(invalidMap2.begin(), invalidMap2.end(), state.Second_Layer[posForMap])>0){continue;} //Verif no obstacles on the position

        else if(std::count(invalidMap1.begin(), invalidMap1.end(), state.First_Layer[posForMap])>0){continue;} //Verif no obstacles on the position

        else if(map[posForMap]!=138){continue;} //Verif no characters on the position

        else{validPos.push_back(move(validNear));}
        
    }
    
    return validPos;
    }


std::vector<int> Character::verifAttackPosition (state::State& state) {
	vector<int> possibleIndexes;
    for(unsigned int i = 0; i < state.getCharacters().size(); i++){
        Character& charac = *state.getCharacters()[i];
        if(charac.getPlayerOwner() != state.turnOwner && charac.getStatus() != DEAD){
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



