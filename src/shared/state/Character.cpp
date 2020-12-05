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


Character::Character (TypeID id, std::string cName, int PosX, int PosY, Spells cSpellSet,int Owner) {

spellSet = cSpellSet;
typeID = id;
status = WAITING;
name = cName;
position.setX(PosX);
position.setY(PosY);
playerOwner=Owner;

sf::Texture character_texture;  // creation texture personnage

	if (id == PLAYER)
		{
		stats.setHealth(150);
		stats.setMovPoints(30);
		stats.setActPoints(15);
		stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);
		character_texture.loadFromFile("../res/player_textures/player.png",sf::IntRect(32,0,32,32));
		sf::Sprite sprite_character_texture;
		character_texture.setSmooth(true); //ameliorer la texture perso
		sprite_character_texture.setTexture(character_texture); //associer la texture perso a son sprite

		}

    else if (id == BOWMAN)
    {
        stats.setHealth(80);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(THROW);
		character_texture.loadFromFile("../res/player_textures/bowman.png",sf::IntRect(32,0,32,32));
		sf::Sprite sprite_character_texture;
		character_texture.setSmooth(true); //ameliorer la texture perso
		sprite_character_texture.setTexture(character_texture); //associer la texture perso a son sprite

    }
	else if (id == SORCERER)
    {
        stats.setHealth(80);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(IGNITE);
		character_texture.loadFromFile("../res/player_textures/sorcerer.png",sf::IntRect(32,0,32,32));
		sf::Sprite sprite_character_texture;
		character_texture.setSmooth(true); //ameliorer la texture perso
		sprite_character_texture.setTexture(character_texture); //associer la texture perso a son sprite

    }
	else if (id == SKELETON)
    {
        stats.setHealth(100);
        stats.setMovPoints(30);
        stats.setActPoints(15);
        stats.setExperience(0);
		stats.setLevel(1);
		spellSet.SetSpell(PUNCH);
		character_texture.loadFromFile("../res/player_textures/skeleton.png",sf::IntRect(32,0,32,32));
		sf::Sprite sprite_character_texture;
		character_texture.setSmooth(true); //ameliorer la texture perso
		sprite_character_texture.setTexture(character_texture); //associer la texture perso a son sprite

    }

}

int Character::getPlayerOwner() const {
    return playerOwner;
}

//std::vector<Position> Character::verifMovingPosition (state::State& state) {

//}

//std::vector<int> Character::verifAttackPosition (state::State& state) {
	
//}
