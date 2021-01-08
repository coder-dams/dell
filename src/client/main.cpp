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
            
            state.modifyMap(456,302);
            
            LoadLayer layer_1, layer_2,layer_3;
            layer_3.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),state.cMap, 30, 30);
            layer_1.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_1(), 30, 30);
            layer_2.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_2(), 30, 30);
            
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
            

            layer_1.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),ngine.getState().First_Layer, 30, 30);
            layer_2.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),ngine.getState().Second_Layer, 30, 30);
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
                usleep(1000000);
                Character& charac0 = *ngine.getState().getCharacters()[0];
                Character& charac1 = *ngine.getState().getCharacters()[1];
                
                int initialXP1 = charac0.getPosition().getX();
                int initialYP1 = charac0.getPosition().getY();
                
                
                if(i==0){
                unique_ptr<engine::Command> ptr_sc(new engine::SelectCharacterCommand(charac0));
                ngine.addCommand(move(ptr_sc));
                Position pos1{initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc1(new engine::MoveCommand(charac0, pos1));
                ngine.addCommand(move(ptr_mc1));
                
                Position pos2{++initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc2(new engine::MoveCommand(charac0, pos2));
                ngine.addCommand(move(ptr_mc2));

                Position pos3{++initialXP1, initialYP1+2};
                unique_ptr<engine::Command> ptr_mc3(new engine::MoveCommand(charac0, pos3));
                ngine.addCommand(move(ptr_mc3));

                unique_ptr<engine::Command> ptr_fc(new engine::SwitchTurnCommand());
                ngine.addCommand(move(ptr_fc));
                cout << "Executing commands" << endl;
                
                ngine.init();
                usleep(100000);
                
                i++;
                
                }
                
            }
	    }
        else if (strcmp(argv[1], "engine") == 0)
        {
            sf::RenderWindow window(sf::VideoMode(512, 512), "Lotus Map");
            engine::Engine ngine{};
            ngine.getState().initializeCharacters();
            
            LoadLayer layer_1, layer_2,layer_3, layer_ui;

            StateEvent se{StateEventID::TURNCHANGED};
            ngine.getState().notifyObservers(se, ngine.getState());

            

            layer_1.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_1(), 30, 30);
            layer_2.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_2(), 30, 30);
            layer_ui.loadTextures(ngine.getState(),"../res/ui_textures/ui.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_UI(), 30, 30);
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
                window.draw(layer_ui);
                window.display();    
                window.clear(); 


                while (window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                        window.close();
                }
                usleep(1000000);
                Character& charac0 = *ngine.getState().getCharacters()[0];
                Character& charac1 = *ngine.getState().getCharacters()[1];
                
                int initialXP1 = charac0.getPosition().getX();
                int initialYP1 = charac0.getPosition().getY();

                
                
                if(i==0){
                unique_ptr<engine::Command> ptr_sc(new engine::SelectCharacterCommand(charac0));
                ngine.addCommand(move(ptr_sc));

                
                unique_ptr<engine::Command> ptr_ac1(new engine::AttackCommand(charac0, charac1));
                ngine.addCommand(move(ptr_ac1));
                

                Position pos1{initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc1(new engine::MoveCommand(charac0, pos1));
                ngine.addCommand(move(ptr_mc1));
                
                Position pos2{++initialXP1, ++initialYP1};
                unique_ptr<engine::Command> ptr_mc2(new engine::MoveCommand(charac0, pos2));
                ngine.addCommand(move(ptr_mc2));

                Position pos3{++initialXP1, initialYP1+2};
                unique_ptr<engine::Command> ptr_mc3(new engine::MoveCommand(charac0, pos3));
                ngine.addCommand(move(ptr_mc3));

                unique_ptr<engine::Command> ptr_fc(new engine::SwitchTurnCommand());
                ngine.addCommand(move(ptr_fc));
                cout << "Executing commands" << endl;
                
                ngine.init();
                usleep(100000);
                i++;
                
                }
                
                
            }
	        
            
        }
        else if (strcmp(argv[1], "random_ai") == 0)
        {

            srand(time(0));
            engine::Engine ngine{};


            ngine.getState().initializeCharacters();
            ngine.getState().First_Layer=LoadLayer::MakeLayer_1();
            ngine.getState().Second_Layer=LoadLayer::MakeLayer_2();
            ngine.getState().UI_Layer=LoadLayer::MakeLayer_UI();

            /*std::vector<Position> validPos;
            validPos=ngine.getState().getCharacters()[1]->verifMovingPosition(ngine.getState());
            */
            std::vector<int> validPos;
            validPos=ngine.getState().getCharacters()[1]->verifAttackPosition(ngine.getState());
            for(int k=0;k<validPos.size();k++){cout<<validPos.size()<<endl;;}
            

            ai::RandomAI rai1;
            ai::RandomAI rai2;
            

            rai1.setPlayerNumber(1);
            rai2.setPlayerNumber(2);
            //-----------------------------
            

            sf::RenderWindow window(sf::VideoMode(480, 480), "Lotus Map");
            render::LoadLayer layer_1, layer_2,layer_3,layer_ui;
            layer_1.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),ngine.getState().First_Layer, 30, 30);
            layer_2.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),ngine.getState().Second_Layer, 30, 30);
            layer_ui.loadTextures(ngine.getState(),"../res/ui_textures/ui.png", sf::Vector2u(16, 16),ngine.getState().UI_Layer, 30, 30);
            

            //StateLayer stateLayer(ngine.getState(), window);
            //stateLayer.initLayer(ngine.getState());
            // Registering observer
            //StateLayer *ptr_stateLayer = &stateLayer;
            //ngine.getState().registerObserver(ptr_stateLayer);
            bool once = true;
            ngine.currentState.end = false;


            while (window.isOpen())
            {
                layer_3.loadTextures(ngine.getState(),"../res/snow-expansion.png", sf::Vector2u(16, 16),ngine.getState().cMap, 30, 30);

                sf::Event event;
                
                window.draw(layer_1);
                window.draw(layer_2);
                window.draw(layer_3);
                window.draw(layer_ui);
                window.display();
               

                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    else if (event.type == sf::Event::KeyPressed)
                    {
                        cout<<"Key pressed"<<endl;
                        if (event.key.code == sf::Keyboard::LShift){
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
