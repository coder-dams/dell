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

std::vector<Position> Position::nearPositions (int x, int y) {

	vector<Position> nP;
	// J'aurais pu utilisé up, down, left, right mais ils ont déjà utilisés
	Position upside{this->getX(), this->getY() + 1};
	Position downside{this->getX(), this->getY() - 1};
	Position leftside{this->getX() - 1, this->getY()};
	Position rightside{this->getX() + 1, this->getY()};
	nP.push_back(move(upside));
	nP.push_back(move(leftside));
	nP.push_back(move(downside));
	nP.push_back(move(rightside));

}

