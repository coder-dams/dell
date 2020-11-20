#include "Character.h"
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



