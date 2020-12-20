#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "../shared/state.h"
#include "render.h"
#include "../shared/engine.h"
#include "../shared/ai.h"

using namespace std;
using namespace state;
using namespace render;
using namespace engine;

const int level_1[] =
            {
                238,238,238,238,238,238,239,238,239,238,239,238,239,238,239,238,239,238,239,238,239,238,239,238,239,238,239,238,239,238,
                238,238,238,239,238,215,216,216,217,216,217,216,217,216,217,216,217,216,217,216,217,216,217,216,217,216,217,216,217,216,
                239,238,215,216,216,195,195,194,195,194,195,194,195,194,195,194,195,194,195,194,195,194,195,194,195,194,195,194,195,194,
                215,216,195,195,194,195,194,195,195,194,195,194,195,194,195,195,195,195,195,195,195,195,194,194,195,92,47,47,47,47,
                195,194,195,195,194,194,194,194,217,216,217,216,217,216,217,217,217,217,217,217,217,217,217,217,217,46,298,273,273,273,
                195,194,194,194,194,194,194,215,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,46,1,135,135,134,
                194,194,194,194,194,194,215,197,197,197,197,197,197,197,197,197,197,197,197,197,197,197,92,47,47,4,44,268,223,223,
                195,194,194,194,194,215,197,197,197,197,197,197,197,197,92,47,47,47,47,47,47,47,4,137,0,0,44,222,177,178,
                194,194,194,216,215,197,238,238,197,197,197,197,197,197,46,0,0,0,0,0,0,0,137,0,0,0,44,222,199,200,
                194,194,215,238,197,238,238,238,197,197,197,197,197,197,91,45,45,2,0,0,0,0,0,0,0,0,44,222,181,182,
                194,215,197,197,238,238,238,238,197,197,197,197,197,197,196,194,194,46,0,0,137,0,0,0,0,0,44,222,203,204,
                215,197,238,238,238,197,197,92,47,47,47,47,47,47,47,47,47,4,0,0,0,0,0,0,0,0,44,222,176,176,
                197,197,197,197,197,197,197,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,137,44,222,176,176,
                197,197,197,197,197,197,197,46,0,0,0,0,0,0,0,0,0,0,276,231,231,231,231,231,231,231,277,222,176,176,
                197,197,197,197,197,197,197,46,0,0,137,0,0,0,276,231,231,231,184,184,184,185,229,229,229,229,274,222,181,182,
                197,197,197,197,92,47,47,4,0,0,0,0,0,276,188,184,184,184,184,184,184,228,0,0,0,0,44,222,203,204,
                197,197,197,92,4,0,0,0,0,0,0,276,231,188,185,229,229,229,186,184,184,228,0,0,137,0,44,222,176,176,
                197,197,92,0,0,0,0,0,137,0,0,230,184,184,228,0,0,0,230,184,184,228,0,0,0,0,44,222,176,176,
                197,197,46,0,0,0,0,0,0,0,0,230,184,184,228,0,0,0,230,184,184,228,0,0,0,0,44,222,176,176,
                197,197,46,0,0,0,0,0,0,0,0,230,184,184,228,0,0,0,230,184,184,228,0,0,0,0,44,222,181,182,
                197,197,46,0,0,0,0,0,0,0,0,230,184,184,187,231,231,231,188,184,184,228,0,0,0,137,44,222,203,204,
                197,197,46,0,0,0,0,0,0,0,0,275,186,184,184,184,184,184,184,184,184,228,0,0,0,0,44,222,176,176,
                197,197,46,0,0,0,0,0,0,0,0,0,275,229,229,229,229,229,229,229,229,274,0,0,0,0,44,222,176,176,
                197,197,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,45,90,269,247,247,
                197,197,46,0,0,0,0,0,0,137,0,0,0,0,0,0,0,137,0,0,0,0,137,0,44,194,196,216,216,216,
                197,197,91,45,45,2,0,0,0,0,137,0,0,0,0,0,0,0,0,137,0,0,0,0,44,216,218,238,238,238,
                238,238,193,194,195,91,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,90,238,240,197,197,197,
                238,238,215,216,217,193,194,195,195,194,194,195,194,194,195,194,194,195,194,194,195,194,194,195,196,197,197,197,197,197,
                238,197,237,238,239,215,216,217,217,216,216,217,216,216,217,216,216,217,216,216,217,216,216,217,218,197,197,197,197,197,
                238,238,238,238,238,237,238,239,239,238,238,239,238,238,239,238,238,239,238,238,239,238,238,239,240,197,197,197,197,197
            };

            const int level_2[] =
            {
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,38,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,92,47,47,47,47,47,93,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,92,4,0,0,0,0,0,44,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,46,0,0,0,0,0,1,90,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,91,45,45,45,45,45,90,156,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,154,155,155,155,155,155,156,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,92,47,47,93,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,91,136,136,90,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,16,154,155,155,156,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,60,82,82,82,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,60,82,82,82,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,107,108,109,138,138,138,138,38,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,129,130,131,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,151,152,153,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,173,174,175,138,138,138,138,138,20,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,42,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,18,19,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,18,19,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,20,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,20,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,
                138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138,138
            };

int main(int argc,char* argv[])
{
    
    if (argc > 1)
    {
        if (strcmp(argv[1], "hello") == 0)
        {
            cout << "Bonjour " << ((argv[2]) ? argv[2] : "tout le monde") << endl;
        }

/*****************************************************/
/*________________PARTIE RENDER______________________*/
/*****************************************************/


        else if (strcmp(argv[1], "render") == 0)
        {
            state::State state("Playing");
            sf::RenderWindow window(sf::VideoMode(512, 512), "Lotus Map");
            window.setFramerateLimit(60);
            // on définit le niveau à l'aide de numéro de tuiles
            
            LoadLayer layer_1, layer_2;
            layer_1.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level_1, 30, 30);
            layer_2.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level_2, 30, 30);
            

            // creation affichage personnage 

            Spells Spell1;
            Spell1.SetSpell(PUNCH);
	        Character Char1(BOWMAN, "bow", 32, 32*10,Spell1,1);
            sf::Sprite Sprite_Char1;
            TypeID id1 = Char1.getType();
            sf::Texture Texture_Character1; 
            Load_Sprite(id1,Sprite_Char1,Texture_Character1);
            Sprite_Char1.setPosition(Char1.position.x,Char1.position.y);
            
            


            
	        Spells Spell2;
            Spell2.SetSpell(IGNITE);
	        Character Char2(PLAYER, "pla", 32*12, 32*6,Spell2,2);
            sf::Sprite Sprite_Char2;
            TypeID id2 = Char2.getType();
            sf::Texture Texture_Character2; 
            Load_Sprite(id2,Sprite_Char2,Texture_Character2);
            Sprite_Char2.setPosition(Char2.position.x,Char2.position.y);

           bool onKeyHold = false; //create a variable that will hold if user press or release a key
           int k=1;
            int a=Char2.position.y/32;
           int b=Char2.position.x/32;

           int i=5;
           int c=Char1.position.y/32;
           int d=Char1.position.x/32;


        


         Char2.setStatus(FIGHTING);



            // on fait tourner la boucle principale
            while (window.isOpen())
            {
                // on gère les évènements
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                        window.close();
                }
               
               if(k==5){
                   Char2.setStatus(WAITING);
                   
               }
               if(i==5){
                   Char2.setStatus(FIGHTING);
                   
               }

/*****************CHAR 2 MOVING******************************/

           
            
        if(Char2.getStatus()==1){

            

                if(k<=4){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            a--; // increment
                             k++;
                             i--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            }
                     


                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            a++; // increment
                             k++;
                             i--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            } 



                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            b++; // increment
                             k++;
                             i--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            }     



                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            b--; // increment
                             k++;
                             i--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            }                                                     
                
                }

                    
                
                Char2.position.y = 32*a;
                Char2.position.x = 32*b;
                Sprite_Char2.setPosition(Char2.position.x,Char2.position.y);}
               

        else if(Char2.getStatus()==2){
            


/*****************CHAR 1 MOVING******************************/
                 if(i<=4){
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            c--; // increment
                            i++;
                            k--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            }
                     


                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            c++; // increment
                            i++;
                            k--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            } 



                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            d++; // increment
                            i++;
                            k--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            }     



                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

                        if ( !onKeyHold ) // check if onKeyHold is false
                            { //if so
                            d--; // increment
                            i++;
                            k--;
                            }
                        onKeyHold = true; // make onKeyHold true
                                }
                        else if ( event.type == sf::Event::KeyReleased ) // check if user released a key
                            { // if so
                             onKeyHold = false; // make onKeyHold false
                            
                            }                                                     
                
                }

            
            
                
                Char1.position.y = 32*c;
                Char1.position.x = 32*d;
                Sprite_Char1.setPosition(Char1.position.x,Char1.position.y); }              











                // on dessine le niveau
                window.clear();
                window.draw(layer_1);
                window.draw(layer_2);
                window.draw(Sprite_Char2);
                window.draw(Sprite_Char1);
                window.display();
                
            }
	    }





	    else if (strcmp(argv[1], "engine") == 0)
        {
	        return 0;
	    }
        else if (strcmp(argv[1], "random_ai") == 0)
        {
            srand(time(0));
            engine::Engine ngine{};

            //TO DO : ngine.getState().initializeMapCell();

            ngine.getState().initializeCharacters();
            ai::RandomAI rai1;
            ai::RandomAI rai2;

            rai1.setPlayerNumber(1);
            rai2.setPlayerNumber(2);
            //-----------------------------

            sf::RenderWindow window(sf::VideoMode(480, 480), "Lotus Map");
            render::LoadLayer layer_1, layer_2;
            layer_1.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),level_1, 30, 30);
            layer_2.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),level_2, 30, 30);

            //StateLayer layer(ngine.getState(), window);
            //layer.initLayer(ngine.getState());

            //StateLayer stateLayer(ngine.getState(), window);
            //stateLayer.initLayer(ngine.getState());
            // Registering observer
            //StateLayer *ptr_stateLayer = &stateLayer;
            //ngine.getState().registerObserver(ptr_stateLayer);
            bool once = true;


            while (window.isOpen())
            {
                sf::Event event;
                if(once){
                    window.draw(layer_1);
                    window.draw(layer_2);
                    once = false;
                }
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    else if (event.type == sf::Event::KeyPressed)
                    {
                        while(ngine.getState().getEnd() == false){
                            rai1.run(ngine);
                            if(ngine.getState().getEnd() == false)
                                rai2.run(ngine);
                        }
                    }
                }
            }
        }
        else
	    {
	        cout << "Usage : ./client hello or ./client render or ./client engine or ./client random_ai" << endl;
	    }
    }
	else
	{
	    cout << "Usage : ./client hello or ./client render or ./client engine or ./client random_ai" << endl;
	}
    
}
