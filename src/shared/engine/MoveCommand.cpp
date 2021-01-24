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
	int deltaPos = abs((deltaCharacter-deltaTarget)); //cas particulier à coder, ex: deltaPos=0 pour currentPos(15,14) et positionTargeted(14,15) alors que le joueur bouge quand meme

	cout<<"The character has : "<<movPoints<<"movement points"<<endl;
		cout<<"The character is moving"<<endl;
		if (movPoints>=1){
			if (movPoints>=deltaPos){
				// mainCharacter.getPosition().setX(positionTarget.getX()); mauvaise méthode(trop de getter), règle: pas 2 "." de get de suite
				state.cMap[mainCharacter.position.y+mainCharacter.position.x*30]=138;
				mainCharacter.position.x = positionTarget.getX();
                mainCharacter.position.y = positionTarget.getY();
				mainCharacter.stats.setMovPoints(movPoints-deltaPos);
				state.cMap[positionTarget.getY()+positionTarget.getX()*30]=mainCharacter.getTileID();
				cout<<"The character was moved"<<endl;
				cout<<"The character has now "<<mainCharacter.stats.getMovPoints()<<" points left"<<endl;
			}
			else{
			cout<<"The character doesn't have enough movements points"<<endl;
			}
		}
		else {
		cout<<"The character doesn't have any movements points"<<endl;
		}

	cout<<"\n"<<endl;

}

