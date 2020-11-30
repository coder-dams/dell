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
 		this->Damage = 0;
 		this->Cost = 0;
 		this->Range = 0;

 }


void Spells::SetSpell (SpellID id){
	if (id==PUNCH) {
		 this->Damage = 20;
		 this->Cost = 3;
 		this->Range = 1;
 } 
	else if (id==IGNITE) {
		 this->Damage = 10;
 		 this->Cost = 3;
		 this->Range = 4;
 } 
	else if (id==THROW) { //On peut enlever la partie throw car les caractéristique du Spell sont initialement celles de THROW
 		this->Damage = 15;
 		this->Cost = 3;
 		this->Range = 2;
}
 }


SpellID Spells::getID ()
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

void Spells::setID (SpellID spellID) {
	this->ID = spellID;
}

void Spells::setDamage (int spellDmg)
{
	this->Damage=spellDmg;
}
void Spells::setCost (int spellCost)
{
	this->Cost=spellCost;
}
void Spells::setRange (int spellRange)
{
	this->Range=spellRange;
}