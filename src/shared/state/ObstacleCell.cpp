#include "ObstacleCellID.h"
#include "ObstacleCell.h"
#include "MapCell.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>


using namespace std;
using namespace state;


ObstacleCell::ObstacleCell(ObstacleCellID id)
{
    this->typeID = id;
}

ObstacleCellID ObstacleCell::getObstacleCellID()
{
    return this->typeID;
}
