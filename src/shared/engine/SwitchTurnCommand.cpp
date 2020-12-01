#include "SwitchTurnCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;


SwitchTurnCommand::SwitchTurnCommand (){
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
    }
    return;
}