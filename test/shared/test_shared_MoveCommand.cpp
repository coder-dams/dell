#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/engine.h"
#include "../../src/shared/state.h"

using namespace ::engine;
using namespace ::state;
using namespace std;
BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestMoveCommand)
{

Engine enginetest;

enginetest.getState().initializeCharacters(); // getState -> currentState marche aussi

Position targetedP2 {20,20}; // cas "doesn't have enough points"
MoveCommand movec2(*enginetest.getState().getCharacters()[1], targetedP2);
movec2.execute(enginetest.currentState);

Position targetedP {10, 14}; // cas qui marche mais movPoints sera à 0 après
MoveCommand movec1(*enginetest.getState().getCharacters()[1], targetedP);
movec1.toRegist();

BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->getPosition().getX(), 15);
BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->getPosition().getY(), 14);
BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->stats.getMovPoints(), 5);

movec1.execute(enginetest.currentState);
BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->getPosition().getX(), 10);
BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->getPosition().getY(), 14);
BOOST_CHECK_LT(enginetest.currentState.getCharacters()[1].get()->stats.getMovPoints(), 5);
movec1.execute(enginetest.currentState); //exécution après que movPoints=0 => cas doesn't have any points 



}

