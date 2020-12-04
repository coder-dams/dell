#include "FreeCellID.h"
#include "FreeCell.h"
#include "MapCell.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;


FreeCell::FreeCell (FreeCellID id, int PosX, int PosY)
{
    this->typeID = id;
    position.setX(PosX);
    position.setY(PosY);

}

FreeCellID FreeCell::getFreeCell()
{
    return this->typeID;
}

void FreeCell::setTypeID(FreeCellID typeID)
{
	this->typeID = typeID;
}

// Ne pas oublier de mettre tous les obstacles à True et les Freecell à false au moment de l'instanciation
// Rappel: Freecell n'est pas toujours à true(ex: quand y'a un joueur sur la case )
bool FreeCell::isOccupied(bool occup) {
    return occup;
}

