#include "FreeCellID.h"
#include "MapCell.h"

/// class FreeCell - 
class FreeCell : public MapCell {
  // Associations
  FreeCellID* unnamed;
  // Attributes
protected:
  FreeCellID typeID;
  // Operations
public:
  FreeCell (FreeCellID id);
  FreeCellID getFreeCell ();
};

