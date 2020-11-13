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


FreeCell::FreeCell (FreeCellID id)
{
    this->typeID = id;
}

FreeCellID FreeCell::getFreeCell()
{
    return this->typeID;
}

void FreeCell::setTypeID(FreeCellID typeID)
{
	this->typeID = typeID;
}

