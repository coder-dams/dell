#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/FreeCell.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    FreeCell cell(GRASS,0,0);
    BOOST_CHECK_EQUAL(cell.getFreeCell(),GRASS);
    cell.setTypeID(DIRT);
    BOOST_CHECK_EQUAL(cell.getFreeCell(),DIRT);
    BOOST_CHECK_EQUAL(cell.isOccupied(true),true);

}



