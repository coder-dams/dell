#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/engine.h"
#include "../../src/client/render.h"
#include "../../src/shared/state.h"

using namespace ::engine;
using namespace ::render;
using namespace ::state;
using namespace std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestAttackCommand)
{
    Engine enginetest;
    enginetest.getState().initializeCharacters();

    AttackCommand c1atkc2{*enginetest.getState().getCharacters()[0], *enginetest.getState().getCharacters()[1]};
    
    //Demander prof pourquoi les pointeurs ne répondent pas
    c1atkc2.execute(enginetest.getState());
    Character c1 = *enginetest.getState().getCharacters()[1];
    BOOST_CHECK_EQUAL(c1.getStats().getHealth(), 150);
    BOOST_CHECK_EQUAL(c1.getStats().getHealth(), 150);

}
