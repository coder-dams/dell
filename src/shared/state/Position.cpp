#include "Position.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <array>

using namespace std;
using namespace state;
    Position::Position(int x, int y)
{
	this->x=x;
	this->y=y;
}

int Position::getX()
{
    return this->x;
}

int Position::getY()
{
    return this->y;
}

void Position::setX(int nX)
{
    this->x = newX;
}

void Position::setY(int nY)
{
    this->y = newY;
}


int Position::distance(Position& other)
{
	return abs(position1.getX() - position2.getX()) + abs(position1.getY() - position2.getY());
}
    // Setters and Getters

