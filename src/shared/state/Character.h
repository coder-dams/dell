#include "Stats.h"
#include "Spells.h"
#include "Element.h"
#include "TypeID.h"
#include "MobTypeID.h"
#include "CharacterStatusID.h"

/// class Character - 
class Character : public Element {
  // Associations
  TypeID* unnamed;
  MobTypeID* unnamed;
  Spells* unnamed;
  CharacterStatusID* unnamed;
  Stats* unnamed;
  // Attributes
protected:
   typeID;
  Stats stats;
  playerTypeID typeID;
  playerStatusID status;
  Spells spells;
   characterID;
  // Operations
public:
  Stats& getStats ();
  Spells& getSpells ();
  PlayerTypeID getType ();
  LevelUp ();
};

