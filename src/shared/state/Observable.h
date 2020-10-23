#include "IObserver.h"

/// class Observable - 
class Observable {
  // Attributes
private:
  std::vector observers;
  // Operations
public:
  void registerObserver (IObserver o);
  void notifyObservers ();
};

