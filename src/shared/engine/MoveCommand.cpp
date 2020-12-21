#include "MoveCommand.h"
#include <iostream>

using namespace engine;
using namespace state;
using namespace std;


MoveCommand::MoveCommand(state::Character &mainC, state::Position &positionT) :
 mainCharacter(mainC), positionTarget(positionT)
{
	cID=MOVE;
	return;
}

Json::Value MoveCommand::toRegist (){
    Json::Value nCommand;

	nCommand["id"] = cID;
	nCommand["player"] = mainCharacter.getPlayerOwner();
    nCommand["xTargeted"] = mainCharacter.getPosition().getX();
    nCommand["yTargeted"] = mainCharacter.getPosition().getY();


	return nCommand;
    
}



void MoveCommand::execute(state::State &state)
{	
	int movPoints = mainCharacter.getStats().getMovPoints();
	int deltaTarget =positionTarget.getX()+positionTarget.getY();
	int deltaCharacter = mainCharacter.getPosition().getX()+mainCharacter.getPosition().getY();
	int deltaPos = abs((deltaCharacter-deltaTarget));

	cout<<"The character has : "<<movPoints<<"movement points"<<endl;
	if(mainCharacter.getStatus()==FIGHTING){
		cout<<"The character is fighting"<<endl;
		if (movPoints>=1){
			if (movPoints>=deltaPos){
				// mainCharacter.getPosition().setX(positionTarget.getX()); mauvaise méthode(trop de getter), règle: pas 2 "." de get de suite
				mainCharacter.position.x = positionTarget.getX();
                mainCharacter.position.y = positionTarget.getY();
				mainCharacter.stats.setMovPoints(movPoints-deltaPos);
				cout<<"The character was moved"<<endl;
				cout<<"The character has now "<<mainCharacter.stats.getMovPoints()<<" points left"<<endl;
			}
			else{
			cout<<"The character doesn't have enough movements points"<<endl;
			}
		}
		else {
		cout<<"The character don't have any movements points"<<endl;
		}
	}
	cout<<"\n"<<endl;
}

