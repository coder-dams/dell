#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Stats.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStats)
{
    {
    Stats myStats {};
    myStats.setHealth(100);
    myStats.setLevel(3);
    myStats.setActPoints(30);
    myStats.setMovPoints(50);
    BOOST_CHECK_EQUAL(myStats.health, 100);
    BOOST_CHECK_EQUAL(myStats.level, 10); // on purpose, expecting false from compiler
    BOOST_CHECK_LE(myStats.actPoints, 32); // Less than equal
    BOOST_CHECK_GT(myStats.movPoints, 11); // Greater than equl

    }
/*
{
    Exemple ex {};
    BOOST_CHECK_EQUAL(ex.x, 0);
    ex.setX(21);
    BOOST_CHECK_EQUAL(ex.x, 21);
  }

  {
    Exemple ex {};
    ex.setX(21);
    BOOST_CHECK_LE(ex.x, 32); // Less than equal
    BOOST_CHECK_GT(ex.x, 11); // Greater than equl
  }
*/

}