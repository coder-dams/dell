#include "Observable.h"
#include <iostream>
#include "IObserver.h"

using namespace state;
using namespace std;

void Observable::registerObserver (IObserver* o)
{
	observers.push_back(o);
}


