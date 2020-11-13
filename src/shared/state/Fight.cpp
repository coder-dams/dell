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

int Fight::getTurn()
{
    return this->turn;
}

int Fight::getEnd()
{
    return this->end;
}

void Fight::setTurn(int newTurn)
{
    this->turn = newTurn;
}

void Fight::setEnd(bool res)
{
    this->end = res;
}

int Fight::getFightAction (StateFightAction state) 
{
	return state;
}

