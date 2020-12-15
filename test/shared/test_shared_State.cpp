#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/State.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    

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
		
		s.setFightAction(F_IDLE);
		BOOST_CHECK_EQUAL(s.getFightAction(),F_IDLE);

		s.setTurnOwner(1);
		BOOST_CHECK_EQUAL(s.getTurnOwner(), 1);


	}


}

