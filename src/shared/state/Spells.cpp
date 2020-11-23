#include "Spells.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <array>

using namespace std;
using namespace state; 


Spells::Spells (){
 		this->Damage = THROW_DMG;
 		this->Cost = THROW_C;
 		this->Range = THROW_R;

 }


void Spells::SetSpell (SpellID id){
	if (id==PUNCH) {
		 this->Damage = PUNCH_DMG;
		 this->Cost = PUNCH_C;
 		this->Range = PUNCH_R;
 } 
	else if (id==PUNCH) {
		 this->Damage = IGNITE_DMG;
 		 this->Cost = IGNITE_C;
		 this->Range = IGNITE_R;
 } 
	else if (id==PUNCH) {
 		this->Damage = THROW_DMG;
 		this->Cost = THROW_C;
 		this->Range = THROW_R;
}
 }


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

