#include "StateFightAction.h"
#include "State.h"

/// class Fight - 
class Fight : public State {
  // Associations
  StateFightAction* unnamed;
  // Attributes
public:
  int turn;
  bool end;
  bool win;
  bool loose;
  // Operations
public:
  int getTurn ();
  int getEnd ();
  void setTurn ();
  void setEnd ();
  int getFightAction (StateFightAction state);
};

