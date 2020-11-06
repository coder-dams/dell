#include "Element.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

using namespace std;
using namespace state;

    // Operations
  public:
    Element::Element()
{
    name = "";
    position.setX(0);
    position.setY(0);
}

    //bool isMapCell ();
    Position &Element::getPosition()
{
    Position &refPosition = position;
    return refPosition;
}

bool MapCell::isMapCell(){
    return true;
}

