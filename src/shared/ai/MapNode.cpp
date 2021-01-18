#include "MapNode.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace ai;
using namespace std;

MapNode::MapNode(int tileID, int newId, bool isObstacle){
    this->tileID = tileID;
    this->id = newId;
    this->isObstacle = isObstacle;
}

vector<MapNode *> MapNode::getNears(){
    return nears;
}

bool MapNode::addNear (MapNode* near){
    nears.push_back(near);
    return true;
}

int MapNode::getTileID(){
    return tileID;
}

bool MapNode::getOccupied (){
    return occupied;
}

void MapNode::setOccuppied (bool newOccupied){
    this->occupied = newOccupied;
}

void MapNode::setTileID(int newTileID){
    this->tileID= newTileID;
}


