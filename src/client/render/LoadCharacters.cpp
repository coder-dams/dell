#include "../render.h"
#include <iostream>

#include <cstdlib>
using namespace std;
using namespace sf;
using namespace state;
using namespace render;


sf::Sprite Load_Sprite(state::Character &mainC)
{

  sf::Texture perso;
  sf::Sprite sprite_perso;


  TypeID ID = mainC.getTypeID();

  if (ID == PLAYER){
    perso.loadFromFile("../res/player_textures/player.png",sf::IntRect(32,0,32,32));
    perso.setSmooth(true); //ameliorer la texture perso
    sprite_perso.setTexture(perso); //associer la texture perso a son sprite

  }



	return sprite_perso;
}	


sf::Texture perso;

