#include "HeuristicAI.h"
#include "state.h"
#include "engine.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <queue>
#include <list>

using namespace ai;
using namespace state;
using namespace engine;
using namespace std;

void HeuristicAI::run(engine::Engine &engine){

}

void HeuristicAI::setPlayerNumber(int np){
     if(np == 1 || np == 2){
        playerNumber = np;
    }
}

int HeuristicAI::getPlayerNumber(){
    return playerNumber;
}

int HeuristicAI::selectCharacter(state::State &state){
return 0;
}


bool HeuristicAI::initMapNodes(state::State &state){
    int k = 0;
    /*MapNode tmp {state.getMap()[i][j]->getPosition().getX(), 
    state.getMap()[i][j]->getPosition().getY(), k, !state.getMap()[i][j]->isSpace()};
    for(unsigned int i = 0; i<state.getMap().size(); i++){
        for(unsigned int j = 0; j<state.getMap().size(); j++){
            map
        }
    }*/
    return true;
}


void HeuristicAI::updateMapNodes(State &state){
    
}

int HeuristicAI::selectTarget(State& state, int selectedCharacIndex){
return 0;
}

int HeuristicAI::findMapNodeIndex(State& state, int characterIndex){
    
    return 0;
}


list<MapNode> HeuristicAI::shortestPath(MapNode &source, MapNode &target){
   
}


std::vector<MapNode> HeuristicAI::callShortestPath(MapNode &source, MapNode &target){
    
}
