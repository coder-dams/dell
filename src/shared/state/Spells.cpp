#include "Spells.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <array>

using namespace std;
using namespace state; 

int Spells::getID ()
{
	return this->ID;
}
int Spells::getDamage ()
{
	return this->Damage;
}
int Spells::getCost ()
{
	return this->Cost;
}
int Spells::getRange ()
{
	return this->Range;
}

