#include "MapCell.h"
#include "Character.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state; 


int MapCell::isOccupied(State& state){
    int res = -1;
    
    vector<std::unique_ptr<Character>> & charactersList = state.getCharacters();
    for (size_t i = 0; i < charactersList.size(); i++)
    {
        Position charapos = charactersList[i]->getPosition();
        Position& charaposref = charapos;
        res = (position.equals(charaposref)) ? i : -1;

        if (res != -1) break;
    }
    return res;
}


