#include "Observable.h"
#include "Cursor.h"
#include "MapCell.h"
#include "Character.h"

/// class State - 
class State : public Observable {
  // Associations
  Cursor* unnamed;
  MapCell* unnamed;
  Character* unnamed;
  // Attributes
public:
  std:vector map;
   players;
  ActiveAction action;
   Cursor;
  // Operations
public:
  State ();
  getCharacters ();
  void initializeCharacters ();
  void initializeMapCell ();
  getAction ();
};

