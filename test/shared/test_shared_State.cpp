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

    BOOST_CHECK_EQUAL(mySpellSet.getDamage(), THROW_DMG);
    BOOST_CHECK_EQUAL(mySpellSet.getRange(), THROW_R);
    BOOST_CHECK_EQUAL(mySpellSet.getCost(), THROW_C);

    mySpellSet.SetSpell(PUNCH);
    BOOST_CHECK_EQUAL(mySpellSet.getDamage(), PUNCH_DMG);
    BOOST_CHECK_EQUAL(mySpellSet.getRange(), PUNCH_R);
    BOOST_CHECK_EQUAL(mySpellSet.getCost(), PUNCH_C);

    mySpellSet.SetSpell(IGNITE);
    BOOST_CHECK_EQUAL(mySpellSet.getDamage(), IGNITE_DMG);
    BOOST_CHECK_EQUAL(mySpellSet.getRange(), IGNITE_R);
    BOOST_CHECK_EQUAL(mySpellSet.getCost(), IGNITE_C);
    
    mySpellSet.setID(THROW);
    mySpellSet.SetSpell(mySpellSet.getID());

    BOOST_CHECK_EQUAL(mySpellSet.getDamage(), THROW_DMG);
    }



}