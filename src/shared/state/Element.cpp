#include "Element.h"
#include "MapCell.h"
#include "Position.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;


  Element::Element()
{
    name = "";
    position.setX(0);
    position.setY(0);
}

Position Element::getPosition()
{
     return this->position;
}

bool Element::isMapCell(){
	if(0<=position.x && position.x<30 && 0<=position.y && position.y<30){return true;}	
	return false;
}

