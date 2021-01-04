#include "SwitchTurnCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;


SwitchTurnCommand::SwitchTurnCommand (){
    cID=TURN_SWITCH;
    return ;
}

//Réinitialiser toutes les caractéristiques des joueurs
void SwitchTurnCommand::execute (state::State& state){
    
    state.setCurrentTurn(state.getCurrentTurn()+1);
    state.setFightAction(F_IDLE);

    for(auto &charsplaying : state.getCharacters()){
         if(charsplaying->getStatus() != DEAD){
            charsplaying->getStats().setActPoints(6);
            charsplaying->getStats().setMovPoints(3);
         }
         if(charsplaying->getPlayerOwner() == state.getTurnOwner()){
                charsplaying->setStatus(FIGHTING);
            }
            // if it's not your turn, then your alive characters will wait.
            else{
                charsplaying->setStatus(WAITING);
              }       
        }
    }

Json::Value SwitchTurnCommand::toRegist (){
    Json::Value nCommand;
	nCommand["id"] = cID;
	
	return nCommand;
    
}