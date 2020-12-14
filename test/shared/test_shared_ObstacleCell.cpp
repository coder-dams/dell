#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/ObstacleCell.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    ObstacleCell cell(TREE,0,0);
    BOOST_CHECK_EQUAL(cell.getObstacleCellID(),TREE);
    ObstacleCell cell2(WALLS,0,0);
    BOOST_CHECK_EQUAL(cell2.getObstacleCellID(),WALLS);
    BOOST_CHECK_EQUAL(cell.isOccupied(true),true);

}



