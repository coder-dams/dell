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

	// State
	{
		State s{"render"};
		s.initializeCharacters();
		//s.initializeMapCell();

		s.setEnd(false);
		BOOST_CHECK_EQUAL(s.getEnd(), false);

		BOOST_CHECK_GT(s.getCharacters().size(), 0); // Greater than equl

		s.setCurrentTurn(2);
		BOOST_CHECK_EQUAL(s.getCurrentTurn(), 2);
		BOOST_CHECK_EQUAL(s.getCursor().isMapCell(), false);
	}


}

