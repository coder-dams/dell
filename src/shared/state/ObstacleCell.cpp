#include "ObstacleCellID.h"
#include "MapCell.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>


using namespace std;
using namespace state;


ObstacleMapCell::ObstacleMapCell(ObstacleMapCellID id)
{
    this->typeID = id;
}

ObstacleMapCellID ObstacleMapCell::getObstacleMapCellID()
{
    return this->typeID;
}
