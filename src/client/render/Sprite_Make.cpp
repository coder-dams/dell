#include "../render.h"
#include <iostream>

#include <cstdlib>
using namespace std;
using namespace sf;
using namespace state;
using namespace render;


sf::Sprite Load_Sprite(state::TypeID id,sf::Sprite& Sprite_Character,sf::Texture& Texture_Character)
{

  if(id==PLAYER){

    Texture_Character.loadFromFile("../res/player_textures/player.png",sf::IntRect(32,0,32,32));
    Sprite_Character.setTexture(Texture_Character); //associer la texture perso a son sprite
    cout<<"un joueur apparait!"<<endl;
  }

 else if(id==BOWMAN){

    Texture_Character.loadFromFile("../res/player_textures/skeleton.png",sf::IntRect(0,0,35,55));
    Sprite_Character.setTexture(Texture_Character); //associer la texture perso a son sprite
    cout<<"un archer apparait!"<<endl;
  }


  return Sprite_Character ;
	
}	



