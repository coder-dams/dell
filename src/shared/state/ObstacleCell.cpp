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


ObstacleCell::ObstacleCell(ObstacleCellID id, int PosX, int PosY)
{
    this->typeID = id;
    position.setX(PosX);
    position.setY(PosY);

}

ObstacleCellID ObstacleCell::getObstacleCellID()
{
    return this->typeID;
}

// Ne pas oublier de mettre tous les obstacles à True et les Freecell à false au moment de l'instanciation

bool ObstacleCell::isOccupied(bool occup) {
    return occup;
}