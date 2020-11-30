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

    //Characters test
    {
    Spells mySpellSet;
    Character c1{PLAYER, "Hamzalemsnap", 0, 0, 1, mySpellSet};
    Character c2{BOWMAN, "Rachidox", 5, 5, 2, mySpellSet};
    Character c3{SKELETON, "Lepo", 10, 10, 3, mySpellSet};
    Character c4{SORCERER, "Abdoulaye", 15, 15, 4, mySpellSet};

    BOOST_CHECK_EQUAL(c1.getType(), PLAYER);
    BOOST_CHECK_EQUAL(c1.getStats().health, 150);

    c1.getStats().setExperience(100);
    c1.LevelUp();
    BOOST_CHECK_EQUAL(c1.getStats().getLevel(), 2);
    BOOST_CHECK_EQUAL(c1.getSpells().getDamage(), 30);
    BOOST_CHECK(!c1.isMapCell());

    BOOST_CHECK_EQUAL(c1.getStatus(), WANDERING);
    c1.setStatus(FIGHTING);
    BOOST_CHECK_EQUAL(c1.getStatus(), FIGHTING);


    }

}