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
	std::unique_ptr<Character> Char1(new Character(BOWMAN, "bow", 15, 15,1,Spell1 	));
	characters.push_back(move(Char1));
	Spells Spell2;
	std::unique_ptr<Character> Char2(new Character(PLAYER, "pla", 15, 14,1,Spell2 	));
	characters.push_back(move(Char2));
   	cout << "Characters created\n";
}


