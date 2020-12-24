#include "Observable.h"
#include <iostream>

using namespace state;
using namespace std;

void Observable::registerObserver (IObserver* observer){
	observers.push_back(observer);
}

void Observable::notifyObservers (const StateEvent& sEvent, State& state){
	for(auto observer : observers){
		observer->stateChanged(sEvent, state);
	}
}