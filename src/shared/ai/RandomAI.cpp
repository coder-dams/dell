#include "ai.h"
#include "engine.h"
#include "state.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

using namespace ai;
using namespace engine;
using namespace state;
using namespace std;

void RandomAI::run(engine::Engine &engine)
{
    
    int randomCharSelected = selectCharacter(engine.getState());
    
    // always select someone
    Character& selectedChar = *engine.getState().getCharacters()[randomCharSelected];
    unique_ptr<Command> selectCommand(new SelectCharacterCommand(selectedChar));
    engine.addCommand(move(selectCommand));
   
    // can attack?
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
        cout<<"ok1"<<endl;
        if(rand()%2)
        {
            if (pa > 0)
            {
                int random = selectedChar.verifAttackPosition(engine.getState())[(rand() % (selectedChar.verifAttackPosition(engine.getState()).size()))];
                Character &targetToAttack = *engine.getState().getCharacters()[rand()%2];
                // choose to attack or to move (0 move, 1 attack)
                cout<<"ok2"<<endl;
                    // attack
                    unique_ptr<Command> atkCmd(new AttackCommand(selectedChar, targetToAttack));
                    engine.addCommand(move(atkCmd));
                    engine.init();
                    pa--;

                    unique_ptr<Command> finTurnCmd(new SwitchTurnCommand());
                    engine.addCommand(move(finTurnCmd));
                    engine.init();
                    return;
              
                
                    // move
                    int randomMove = (rand() % selectedChar.verifMovingPosition(engine.getState()).size());
                    Position& p = selectedChar.verifMovingPosition(engine.getState())[randomMove];
                    unique_ptr<Command> mvCmd(new MoveCommand(selectedChar, p));
                    engine.addCommand(move(mvCmd));
                    engine.init();
                    pm--;
                    cout<<p.getX()<<p.getY()<<endl;
                    cout<<engine.getState().cMap[p.getX()*30+p.getY()]<<endl;
            }
            unique_ptr<Command> endTurnCmd(new SwitchTurnCommand());
            engine.addCommand(move(endTurnCmd));
            engine.init();
            
        }
        else
        {
            
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
                //{
                    // just attack
                    int random = selectedChar.verifAttackPosition(engine.getState())[(rand() % (selectedChar.verifAttackPosition(engine.getState()).size()))];
                    Character &targetToAttack = *engine.getState().getCharacters()[rand()%2];                
                    unique_ptr<Command> atkCmd(new AttackCommand(selectedChar, targetToAttack));
                    engine.addCommand(move(atkCmd));
                    engine.init();

                    unique_ptr<Command> endTurnCmd(new SwitchTurnCommand());
                    engine.addCommand(move(endTurnCmd));
                    engine.init();
                    return;
                }
            }
            unique_ptr<Command> finTurnCmd(new SwitchTurnCommand());
            engine.addCommand(move(finTurnCmd));
            engine.init();
            return;
            
        }
    return;
}

int RandomAI::selectCharacter (state::State& state){
    std::vector<int> posibleIndex;

    for( int i = 0; i < state.getCharacters().size(); i++){
        Character &charac = *state.getCharacters()[i];
        if(state.getTurnOwner() == playerNumber && charac.getStatus() != DEAD)
            posibleIndex.push_back(i);
    }
    

    //int randomNumber = rand() % 1;
    
    return 0;
}

int RandomAI::getPlayerNumber (){
    return playerNumber;
}

void RandomAI::setPlayerNumber (int pn){
    if(pn == 1 || pn == 2){
        playerNumber = pn;
    }
}
