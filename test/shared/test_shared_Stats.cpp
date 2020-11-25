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
    myStats.setExperience(75);


    BOOST_CHECK_EQUAL(myStats.getHealth(), 100);
    BOOST_CHECK_EQUAL(myStats.getLevel(), 10); // on purpose, expecting false from compiler
    BOOST_CHECK_LE(myStats.getActPoints(), 32); // Less than equal
    BOOST_CHECK_GT(myStats.getMovPoints(), 11); // Greater than equl
    BOOST_CHECK_EQUAL(myStats.getExperience(), 75);
    

    }

}

// Remove/recreate build -> cmake .. ->make code-coverage