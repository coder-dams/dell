#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/engine.h"

using namespace ::engine;
using namespace std;
BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestMoveCommand)
{

Engine enginetest;
Command cmdtest(1);
cmdtest.execute(enginetest.currentState);

BOOST_CHECK_EQUAL(cmdtest.getCommandTypeId(),1);

}
