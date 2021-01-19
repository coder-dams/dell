#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/engine.h"

using namespace ::engine;
using namespace state;
using namespace std;
BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestSelectCharacterCommand) // tests succesful 
{

Engine enginetest;

enginetest.currentState.initializeCharacters();

SelectCharacterCommand selectPlayer(*enginetest.currentState.getCharacters()[1]);

enginetest.currentState.setCurrentTurn(1);
selectPlayer.execute(enginetest.currentState);
BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[1].get()->getStatus(), SELECTED);
BOOST_CHECK_EQUAL(enginetest.currentState.getCharacters()[0].get()->getStatus(), FIGHTING);
}
