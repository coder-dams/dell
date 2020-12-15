#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/State.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    //Spells test
    {
    Spells mySpellSet {};

    mySpellSet.setDamage(100);
    mySpellSet.setRange(100);
    mySpellSet.setCost(100);
    BOOST_CHECK_EQUAL(100, mySpellSet.getDamage());
    BOOST_CHECK_EQUAL(100, mySpellSet.getRange());
    BOOST_CHECK_EQUAL(100, mySpellSet.getCost());

    mySpellSet.SetSpell(PUNCH);
    mySpellSet.SetSpell(IGNITE);
    mySpellSet.setID(THROW);
    mySpellSet.SetSpell(mySpellSet.getID());

    }


}

