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

void MapNode::setOccupied (bool newOccupied){
    this->occupied = newOccupied;
}

void MapNode::setTileID(int newTileID){
    this->tileID= newTileID;
}

bool MapNode::isOccupied(int tile) {
    vector<int> occupiedTiles = {268,223,222,177,178,199,200,181,182,203,204,176,196,194,197,
    238,239,215,216,217,195,237}; // liste de tuiles où le perso ne peut pas aller
    for(int i =0; i<occupiedTiles.size(); i++) {
        if(tile==occupiedTiles[i]) {
            return true;
        }
        else {
            return false;
        }
    }

}


