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
    int randomCharSelected = selectCharacter(engine.getState());
    
    // always select someone just like in RandomIA
    Character& selectedChar = *engine.getState().getCharacters()[randomCharSelected];
    unique_ptr<Command> selectCommand(new SelectCharacterCommand(selectedChar));
    engine.addCommand(move(selectCommand));
   
    // can attack? Basically Heuristic IA starts just like Random
    vector<int> ValidPos;
    ValidPos=engine.getState().getCharacters()[1]->verifAttackPosition(engine.getState());
    cout<<ValidPos.size()<<endl;
    usleep(100000);

    
    
    
    if (selectedChar.verifAttackPosition(engine.getState()).size() > 0)
    {
        // can attack
        cout << "first if can attack ? true " << endl;
        int pa = selectedChar.getStats().getActPoints();
        int pm = selectedChar.getStats().getMovPoints();

            if (pa > 0)
            {
                //int random = selectedChar.verifAttackPosition(engine.getState())[(rand() % (selectedChar.verifAttackPosition(engine.getState()).size()))];
                Character &targetToAttack = *engine.getState().getCharacters()[rand()%2];
                // choose to attack or to move (0 move, 1 attack)

                    // attack
                    unique_ptr<Command> atkCmd(new AttackCommand(selectedChar, targetToAttack));
                    engine.addCommand(move(atkCmd));
                    engine.init();
                    pa--;

                    //unique_ptr<Command> finTurnCmd(new SwitchTurnCommand());
                    //engine.addCommand(move(finTurnCmd));
                    //engine.init();
                   // return;
                }
            else {
                    // move
                    int randomMove = (rand() % selectedChar.verifMovingPosition(engine.getState()).size());
                    Position& p = selectedChar.verifMovingPosition(engine.getState())[randomMove];
                    unique_ptr<Command> mvCmd(new MoveCommand(selectedChar, p));
                    engine.addCommand(move(mvCmd));
                    engine.init();
                    pm--;
              }
            
            unique_ptr<Command> endTurnCmd(new SwitchTurnCommand());
            engine.addCommand(move(endTurnCmd));
            engine.init();
            
    }
    else
        {
            int pa = selectedChar.getStats().getActPoints();
            int pm = selectedChar.getStats().getMovPoints();
            while ( pm > 0)
            {
                
                // can NOT attack, JUST MOVE.
                int randomMove = (rand() % selectedChar.verifMovingPosition(engine.getState()).size());
                Position p{selectedChar.verifMovingPosition(engine.getState())[randomMove].getX(), selectedChar.verifMovingPosition(engine.getState())[randomMove].getY()};
                unique_ptr<Command> mvCmd(new MoveCommand(selectedChar, p));
                engine.addCommand(move(mvCmd));
                engine.init();
                pm--;
                cout << " move executed " << endl;

                // now i was deplaced, can attack?
                if (selectedChar.verifAttackPosition(engine.getState()).size())
                {
                    // just attack
                    //int random = selectedChar.verifAttackPosition(engine.getState())[(rand() % (selectedChar.verifAttackPosition(engine.getState()).size()))];
                    Character &targetToAttack = *engine.getState().getCharacters()[rand()%2];                
                    unique_ptr<Command> atkCmd(new AttackCommand(selectedChar, targetToAttack));
                    engine.addCommand(move(atkCmd));
                    engine.init();
                    pa--;
                }
                    //unique_ptr<Command> endTurnCmd(new SwitchTurnCommand());
                    //engine.addCommand(move(endTurnCmd));
                    //engine.init();
                    //return;
                
            }
        
    unique_ptr<Command> finTurnCmd(new SwitchTurnCommand());
    engine.addCommand(move(finTurnCmd));
    engine.init();
    //return;
    }     
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
    std::vector<int> posibleIndex;

    for( unsigned i = 0; i < state.getCharacters().size(); i++){
        Character &charac = *state.getCharacters()[i];
        if(state.getTurnOwner() == playerNumber && charac.getStatus() != DEAD)
            posibleIndex.push_back(i);
    }
        
    return 0;
}


bool HeuristicAI::initMapNodes(state::State &state){
    /* initializes mapNodes vector, which is a grid of all cells where a character can
walk on a given moment. So, if a cell its obstacle, isnt added to this vector.
even if a cell its occuped, isnt added to this vector.*/
    int k = 0;
    for(unsigned int i = 0; i<state.getMap().size(); i++){
        mapNodes.push_back(MapNode{state.getMap()[i], k, false});
        if(mapNodes[i].isOccupied(state.getMap()[i])==true){
            mapNodes[i].setOccupied(true);
        }
        k++;
    // to complete
    }
    return true;
} 


void HeuristicAI::updateMapNodes(State &state){
    for(auto &mapNode : mapNodes){
        mapNode.setOccupied(false);
        for(auto &charac : state.getCharacters()) {
            //if(charac->){

            }
        }
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
