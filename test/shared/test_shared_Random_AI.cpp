
#include <boost/test/unit_test.hpp>
#include <vector>
#include "../../src/shared/ai.h"
#include "../../src/shared/state.h"
#include "../../src/shared/engine.h"

using namespace ::ai;
using namespace ::engine;
using namespace ::state;
using namespace std;
BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestEngineNamespace)
{
    
    {
        //srand(time(0));
        engine::Engine ngine;

        ai::RandomAI rai;
        
        rai.setPlayerNumber(1);
	BOOST_CHECK_EQUAL(1, rai.getPlayerNumber());

        //rai.run(ngine);
    }
}

/* vim: set sw=2 sts=2 et : */
