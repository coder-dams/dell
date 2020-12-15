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
enginetest.getState().initializeCharacters();
Position targetedP(10, 10);

MoveCommand movec1(*enginetest.getState().getCharacters()[1], targetedP);

Character c1 = *enginetest.getState().getCharacters()[1];
movec1.execute(enginetest.getState());
BOOST_CHECK_EQUAL(c1.getPosition().getX(), 10);

}
