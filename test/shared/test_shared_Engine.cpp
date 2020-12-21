#include "../../src/shared/engine.h"
#include "../../src/client/render.h"
#include <boost/test/unit_test.hpp>


using namespace ::engine;
using namespace ::render;
using namespace std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestEngineNamespace)
{
    {
        /*
        Engine enginetest;
        enginetest.getState().initializeCharacters();

        unique_ptr<engine::Command> ptr_sc(new engine::SelectCharacterCommand(*enginetest.getState().getCharacters()[0]));
        enginetest.addCommand(move(ptr_sc));

        unique_ptr<engine::Command> ptr_ac1(new engine::AttackCommand(*enginetest.getState().getCharacters()[0], *enginetest.getState().getCharacters()[1]));
        enginetest.addCommand(move(ptr_ac1));

        unique_ptr<engine::Command> ptr_fc(new engine::SwitchTurnCommand());
        enginetest.addCommand(move(ptr_fc));
        enginetest.init();
        */
    }
}