#include "StateWanderAction.h"
#include "State.h"

/// class Wander - 
class Wander : public State {
  // Associations
  StateWanderAction* unnamed;
  // Operations
public:
  int getWanderAction (StateWanderAction state);
};

