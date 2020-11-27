#include "StateFightAction.h"
#include "State.h"
#include "Fight.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;

    // Operations

int Fight::getCurrentTurn()
{
    return this->currentTurn;
}

int Fight::getEnd()
{
    return this->end;
}

void Fight::setCurrentTurn(int newTurn)
{
    this->currentTurn = newTurn;
}

void Fight::setEnd(bool res)
{
    this->end = res;
}

StateFightAction Fight::getFightAction () 
{
	return this->currentFightAction;
}

void Fight::setFightAction (StateFightAction newStateFightAction) 
{
	 this->currentFightAction=newStateFightAction;
}

void Fight::setWin(bool sbwon)
{
    this->win = sbwon;
}