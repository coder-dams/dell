#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
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

        std::vector<int> level_1
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

            
            std::vector<int> level_2
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
        else if (strcmp(argv[1], "render") == 0)
        {
            state::State state("Playing");
            sf::RenderWindow window(sf::VideoMode(512, 512), "Lotus Map");
            // on définit le niveau à l'aide de numéro de tuiles
            
            state.modifyMap(0,302);
            
            LoadLayer layer_1, layer_2,layer_3;
            layer_3.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),state.cMap, 30, 30);
            layer_1.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level_1, 30, 30);
            layer_2.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level_2, 30, 30);
            
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

                // on dessine le niveau
                
                window.draw(layer_1);
                window.draw(layer_2);
                window.draw(layer_3);
                window.display();
                
            }
	    }
	    else if (strcmp(argv[1], "engine") == 0)
        {
            state::State state("Engine");
            sf::RenderWindow window(sf::VideoMode(512, 512), "Lotus Map");
            // on définit le niveau à l'aide de numéro de tuiles
            engine::Engine ngine{};
            state.initializeCharacters();
            
            LoadLayer layer_1, layer_2,layer_3;
            
            layer_1.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level_1, 30, 30);
            layer_2.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level_2, 30, 30);
            
            // on fait tourner la boucle principale
            while (window.isOpen())
            {
                int i=0;
                state.modifyMap(i,302);
                layer_3.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),state.cMap, 30, 30);

                // on gère les évènements
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                        window.close();
                }

                // on dessine le niveau
                
                window.draw(layer_1);
                window.draw(layer_2);
                window.draw(layer_3);
                window.display();
                window.clear();
                if(i<29){i++;};
                
            }
	        return 0;
	    }
        else if (strcmp(argv[1], "test") == 0)
        {
            sf::RenderWindow window(sf::VideoMode(512, 512), "Lotus Map");
            engine::Engine ngine{};
            ngine.getState().initializeCharacters();
            
            StateLayer stateLayer(ngine.getState(), window,"engine");
            StateLayer *ptr_stateLayer = &stateLayer;
            LoadLayer layer_1, layer_2,layer_3;

            StateEvent se{StateEventID::TURNCHANGED};
            ngine.getState().notifyObservers(se, ngine.getState());
            

            layer_1.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),level_1, 30, 30);
            layer_2.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),level_2, 30, 30);
            int i=0;
            // on fait tourner la boucle principale
            while (window.isOpen())
            {
                layer_3.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),ngine.getState().cMap, 30, 30);

                // on gère les évènements
                sf::Event event;
                window.draw(layer_1);
                window.draw(layer_2);
                window.draw(layer_3);
                window.display();    
                window.clear(); 


                while (window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                        window.close();
                }
                
                Character& charac0 = *ngine.getState().getCharacters()[0];
                Character& charac1 = *ngine.getState().getCharacters()[1];
                
                int initialXP1 = charac0.getPosition().getX();
                int initialYP1 = charac0.getPosition().getY();

                int initialXP2 = charac1.getPosition().getX();
                int initialYP2 = charac1.getPosition().getY();
                
                
                if(i==0){
                unique_ptr<engine::Command> ptr_sc(new engine::SelectCharacterCommand(charac0));
                ngine.addCommand(move(ptr_sc));
                Position pos1{initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc1(new engine::MoveCommand(charac0, pos1));
                ngine.addCommand(move(ptr_mc1));
                /*
                Position pos2{initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc2(new engine::MoveCommand(*ngine.getState().getCharacters()[0], pos2));
                ngine.addCommand(move(ptr_mc2));

                Position pos3{initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc3(new engine::MoveCommand(*ngine.getState().getCharacters()[0], pos3));
                ngine.addCommand(move(ptr_mc3));

                unique_ptr<engine::Command> ptr_fc(new engine::SwitchTurnCommand());
                ngine.addCommand(move(ptr_fc));
                cout << "Adding commands for this turn FINISHED. Executing..." << endl;
                */
                ngine.init();
                usleep(100000);

                i++;
        
                
                }
                
                
                
            }
	        
            
        }
        else if (strcmp(argv[1], "random_ai") == 0)
        {
            /*srand(time(0));
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
            ngine.currentState.end = false;


            while (window.isOpen())
            {
                sf::Event event;
                if(once){
                    window.draw(layer_1);
                    window.draw(layer_2);
                    window.display();
                    once = false;
                }
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    else if (event.type == sf::Event::KeyPressed)
                    {
                        cout<<"Key pressed"<<endl;
                        if (event.key.code == sf::Keyboard::RShift){
                            cout<<"LShift pressed"<<endl;
                            while(ngine.currentState.end == false){
                                cout<<"Player1 playing"<<endl;
                                rai1.run(ngine);
                                if(ngine.currentState.end == false){
                                    cout<<"Player2 playing"<<endl;
                                    rai2.run(ngine);
                                }
                            }
                        }
                    }
                }
            }*/
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
