#include "Position.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <array>

using namespace std;
using namespace state;

Position::Position()
{
	this->x=0;
	this->y=0;
}


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
    this->x = nX;
}

void Position::setY(int nY)
{
    this->y = nY;
}


int Position::distance(Position& position1, Position& position2)
{
	return abs(position1.getX() - position2.getX()) + abs(position1.getY() - position2.getY());
}

std::vector<Position> Position::nearPositions (Position pos) {

	vector<Position> nP;
	// J'aurais pu utilisé up, down, left, right mais ils ont déjà utilisés
	Position upside{pos.getX(), pos.getY() + 1};
	Position downside{pos.getX(), pos.getY() - 1};
	Position leftside{pos.getX() - 1, pos.getY()};
	Position rightside{pos.getX() + 1, pos.getY()};
	nP.push_back(move(upside));
	nP.push_back(move(leftside));
	nP.push_back(move(downside));
	nP.push_back(move(rightside));
	return(nP);


}

bool Position::equals(Position& other){
	return (this->x == other.getX() && this->y == other.getY()); 
}


