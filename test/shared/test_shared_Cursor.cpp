#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Cursor.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    Position nextPos{0, 0};
	Cursor c{1, 1};
	BOOST_CHECK_EQUAL(c.isMapCell(), false);
	c.move(nextPos);
	BOOST_CHECK_EQUAL(c.getPosition().equals(nextPos), true);

}



