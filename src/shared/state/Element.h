#include "Position.h"

/// class Element - 
class Element {
  // Attributes
public:
  std::string name;
  Position position;
   tileCode;
  // Operations
public:
  Element ();
  bool isMapCell ();
  Position& getPosition ();
};

