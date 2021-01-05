#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/engine.h"
#include "../../src/client/render.h"
#include "../../src/shared/state.h"

using namespace ::engine;
using namespace ::render;
using namespace ::state;
using namespace std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestAttackCommand)
{
    
    Engine enginetest;
    enginetest.currentState.initializeCharacters();
    AttackCommand c1atkc2{*enginetest.currentState.getCharacters()[0], *enginetest.currentState.getCharacters()[1]};
    
    BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->getStats().getHealth(), 150);
    BOOST_CHECK_EQUAL(enginetest.currentState.characters[0]->stats.actPoints, 5); 

    c1atkc2.execute(enginetest.currentState);  
    BOOST_CHECK_EQUAL(enginetest.currentState.characters[1]->stats.health, 135); 
    BOOST_CHECK_EQUAL(enginetest.currentState.characters[0]->stats.actPoints, 2); 

}