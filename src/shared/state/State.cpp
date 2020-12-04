#include "State.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <map>

using namespace std;
using namespace state;


State::State(std::string newMode)
{
    Cursor c{15, 15};
    this->cursor = c;
    this->mode=newMode;
}

std::vector<std::unique_ptr<Character>> &State::getCharacters()
{
    vector<unique_ptr<Character>> &charac = characters;
    return charac;
}



  Cursor &State::getCursor()
{
    Cursor &refCursor = cursor;
    return refCursor;
}


void State::initializeCharacters (){

	Spells Spell1;
    Spell1.SetSpell(PUNCH);
	std::unique_ptr<Character> Char1(new Character(BOWMAN, "bow", 15, 15,Spell1,1));
	characters.push_back(move(Char1));
	Spells Spell2;
    Spell2.SetSpell(IGNITE);
	std::unique_ptr<Character> Char2(new Character(PLAYER, "pla", 15, 14,Spell2,2));
	characters.push_back(move(Char2));
   	cout << "Characters created\n";
}

int State::getCurrentTurn()
{
    return this->currentTurn;
}

int State::getEnd()
{
    return this->end;
}

void State::setCurrentTurn(int newTurn)
{
    this->currentTurn = newTurn;
}

void State::setTurnOwner(int newOwner)
{
    this->turnOwner = newOwner;
}

int State::getTurnOwner()
{
    return this->turnOwner;
}

void State::setEnd(bool res)
{
    this->end = res;
}

StateFightAction State::getFightAction () 
{
	return this->currentFightAction;
}

void State::setFightAction (StateFightAction newStateFightAction) 
{
	 this->currentFightAction=newStateFightAction;
}

void State::setWin(bool sbwon)
{
    this->win = sbwon;
}

std::string State::getMode(){
    return mode;
}
