#include "Spells.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <array>

using namespace std;
using namespace state; 

// Les setters pas forcément nécessaires, vu que toutes les config dont on a besoin sont dans setSpell
//On peut les enlever
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
	else if (id==IGNITE) {
		 this->Damage = IGNITE_DMG;
 		 this->Cost = IGNITE_C;
		 this->Range = IGNITE_R;
 } 
	else if (id==THROW) { //On peut enlever la partie throw car les caractéristique du Spell sont initialement celles de THROW
 		this->Damage = THROW_DMG;
 		this->Cost = THROW_C;
 		this->Range = THROW_R;
}
 }


SpellID Spells::getID ()
{
	return this->ID;
}
DamageID Spells::getDamage ()
{
	return this->Damage;
}
CostID Spells::getCost ()
{
	return this->Cost;
}
RangeID Spells::getRange ()
{
	return this->Range;
}

void Spells::setID (SpellID spellID) {
	this->ID = spellID;
}

