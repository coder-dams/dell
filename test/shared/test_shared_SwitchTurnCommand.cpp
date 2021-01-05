#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/engine.h"

using namespace ::engine;
using namespace std;
BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestSwitchTurnCommand)
{
    
    Engine enginetest;
    enginetest.currentState.initializeCharacters();
    SwitchTurnCommand swt{};
    swt.toRegist();

    enginetest.currentState.characters[1].get()->stats.setMovPoints(1);
    enginetest.currentState.characters[1].get()->stats.setActPoints(1);

    BOOST_CHECK_EQUAL(enginetest.currentState.characters[1]->stats.actPoints, 1); 
    BOOST_CHECK_EQUAL(enginetest.currentState.characters[1]->stats.movPoints, 1); 

    enginetest.currentState.setTurnOwner(enginetest.currentState.getCharacters()[0].get()->getPlayerOwner());
    BOOST_CHECK_EQUAL(enginetest.currentState.turnOwner, enginetest.currentState.getCharacters()[0].get()->getPlayerOwner()); 

    swt.execute(enginetest.currentState);  
    BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1]->stats.actPoints, 6); 
    BOOST_CHECK_EQUAL(enginetest.currentState.characters[1]->stats.movPoints, 3); 
    
}