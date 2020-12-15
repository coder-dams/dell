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
    //Characters test
    {
    State st{"gameTest"};
    Spells mySpellSet;
    Character c1{PLAYER, "Hamzalemsnap", 0, 0, mySpellSet,1};
    Character c2{BOWMAN, "Rachidox", 5, 5, mySpellSet,1};
    Character c3{SKELETON, "Lepo", 10, 10, mySpellSet,1};
    Character c4{SORCERER, "Abdoulaye", 15, 15, mySpellSet,1};

    BOOST_CHECK_EQUAL(c1.getPlayerOwner(), 1);

    BOOST_CHECK_EQUAL(c1.getType(), PLAYER);
    BOOST_CHECK_EQUAL(c1.getStats().health, 150);

    c1.getStats().setExperience(100);
    c1.LevelUp();
    BOOST_CHECK_EQUAL(c1.getStats().getLevel(), 1);
    BOOST_CHECK_EQUAL(c1.getSpells().getDamage(), 20);
    BOOST_CHECK(!c1.isMapCell());

    BOOST_CHECK_EQUAL(c1.getStatus(), WAITING);
    c1.setStatus(FIGHTING);
    BOOST_CHECK_EQUAL(c1.getStatus(), FIGHTING);


    c1.verifMovingPosition(st);
    st.initializeCharacters();
    c1.verifAttackPosition(st);

    }

}