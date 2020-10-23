#include "ObstacleCellID.h"
#include "MapCell.h"

/// class ObstacleCell - 
class ObstacleCell : public MapCell {
  // Associations
  ObstacleCellID* unnamed;
  // Attributes
protected:
  ObstacleCellID typeID;
  // Operations
public:
  ObstacleCell (ObstacleCellID id);
  ObstacleCellID getObstacleCellID ();
};

