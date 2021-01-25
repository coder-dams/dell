#include "engine.h"
#include "render.h"
#include "state.h"
#include "client.h"
#include "ai.h"
#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <pthread.h>
using namespace state;
using namespace engine;
using namespace render;
using namespace std;
using namespace client;
using namespace ai;

bool canRunEngine = false;
bool runFunctionCalled = true;



void threadEngine(Engine *ptr)
{
    while (runFunctionCalled) // will be changed by the thread
    {
        usleep(1000);
        if (canRunEngine)
        {
            ptr->init();
            canRunEngine = false;
        }
    }
}

Client::Client(sf::RenderWindow &window) : window(window)
{
    

    engine.getState().initializeCharacters();
    engine.getState().First_Layer=LoadLayer::MakeLayer_1();
    engine.getState().Second_Layer=LoadLayer::MakeLayer_2();
    engine.getState().UI_Layer=LoadLayer::MakeLayer_UI();
    engine.getState().setTurnOwner(0);


    ai::RandomAI aiPlayer1;
    ai::RandomAI aiPlayer2;

    aiPlayer1.setPlayerNumber(1);
    aiPlayer2.setPlayerNumber(2);

}

void Client::engineUpdating()
{
    canRunEngine = true;
    usleep(150000);
}

void Client::engineUpdated()
{
}
bool once = true;

void Client::run()
{
    StateLayer stateLayer(engine.getState(), window,"thread");
   

   



    std::thread thread (threadEngine, &engine);



    stateLayer.initLayer(engine.getState());
    stateLayer.draw(window);
    sf::Event event;
    

    while (window.pollEvent(event))
    {
        
        if (event.type == sf::Event::KeyPressed)
        {
            cout<<"Key pressed"<<endl;
            if (event.key.code == sf::Keyboard::LShift){
                cout<<"LShift pressed"<<endl;
                while(true){
                    
                    for(int k=0;k<engine.getState().getCharacters().size();k++){
                        engine.getState().setTurnOwner(0);
                        cout<<"Player1 playing"<<endl;
                        aiPlayer1.run(engine);
                        stateLayer.initLayer(engine.getState());
                        stateLayer.draw(window);
                                
			            engine.getState().setTurnOwner(1);
                        cout<<"Player2 playing"<<endl;
                        aiPlayer2.run(engine);
                        stateLayer.initLayer(engine.getState());
                        stateLayer.draw(window);
                        if (event.type == sf::Event::Closed ) window.close();

                    }
                }
            }
        }
    }
    runFunctionCalled = false;
    thread.join();
}


