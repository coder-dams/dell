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

    for(auto &charsplaying : state.characters) {
         if(charsplaying->getStatus() != DEAD){
            // faire un switch case pour adapter la réinitialisation des points mov et atc selon les joueurs(PLAYER, etc...)
            charsplaying->stats.setActPoints(6);
            charsplaying->stats.setMovPoints(3); // charsplaying->getStats().setMovPoints(3); ne marcherait pas car le get fait toujours des copies
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