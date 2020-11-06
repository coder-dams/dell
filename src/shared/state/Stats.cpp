#include "Stats.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;


    int Stats::getHealth ()
{
    return this->health;
}
    int Stats::getActPoints ()
{
    return this->actPoints;
}				
    int Stats::getMovPoints ()
{
    return this->movPoints;
}
    int Stats::getExperience ()
{
    return this->experience;
}
    int Stats::getLevel ()
{
    return this->level;
}

void Stats::setHealth(int nHealth)
{
    this->health = newHealth;
}
    void Stats::setActPoints  (int nAct)
{
    this->health = nAct;
}
    void Stats::setMovPoints (int nMov)
{
    this->health = nMov;
}
    void Stats::setExperience (int nExp)
{
    this->health = nExp;
}
    void Stats::setLevel (int nLev)
{
    this->health = nLev;
}

