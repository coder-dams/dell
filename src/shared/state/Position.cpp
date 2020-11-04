#include "Position.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

namespace state {


Position::Position(int x, int y){
	this->x=x;
	this->y=y;
}

int Position::getX(){
    return this->x;
}

int Position::getY(){
    return this->y;
}

void Position::setX (int nX) {
    this->x = nX;
}


void Position::setY (int nY) {
    this->y = nY;
}

}

