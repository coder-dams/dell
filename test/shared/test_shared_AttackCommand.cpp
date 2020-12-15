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
    Engine enginetest{};
    enginetest.getState().initializeCharacters();

    AttackCommand c1atkc2{*enginetest.getState().getCharacters()[0], *enginetest.getState().getCharacters()[1]};
    
    //Demander prof pourquoi les pointeurs ne répondent pas
    BOOST_CHECK_EQUAL(enginetest.getState().getCharacters()[0].get()->getStats().getHealth(), 130);
    c1atkc2.execute(enginetest.getState());
    BOOST_CHECK_EQUAL(enginetest.getState().getCharacters()[0].get()->getStats().getHealth(), 130);
    BOOST_CHECK_EQUAL(enginetest.getState().getCharacters()[0].get()->getStats().getHealth(), 135);

}