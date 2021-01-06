#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/StateEvent.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{

StateEvent se_test(TURNCHANGED);
BOOST_CHECK_EQUAL(se_test.stateEventID, TURNCHANGED)

se_test.setStateEventID(WINNER);
BOOST_CHECK_EQUAL(se_test.stateEventID, WINNER);

}
