#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Position.h"

using namespace ::state;
using namespace ::std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    Position pos;
    Position pos2(1,5);

    BOOST_CHECK_EQUAL(pos2.getX(),1);
    BOOST_CHECK_EQUAL(pos2.getY(),5);
    BOOST_CHECK_EQUAL(pos.distance(pos,pos2),6);
    BOOST_CHECK_EQUAL(false,pos.equals(pos2));








}



