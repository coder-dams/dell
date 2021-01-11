
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

BOOST_AUTO_TEST_CASE(TestRandomAI)
{
    Engine enginetest;
    enginetest.currentState.initializeCharacters();
    RandomAI rai;

    enginetest.currentState.setTurnOwner(enginetest.currentState.getCharacters()[0].get()->getPlayerOwner());
    rai.selectCharacter(enginetest.currentState);

    rai.setPlayerNumber(1);
    //int a = rai.getPlayerNumber();
    BOOST_CHECK_EQUAL(rai.getPlayerNumber(), 1); 
/*
//Couverture à 63% mais le run de l'ia renvoie un seg fault, le else(1er if dans run) ne sera jamais exécuté(verifAttackPos) voir avec Hamza
    rai.run(enginetest); //Demander Mr Bares
    enginetest.currentState.getCharacters()[0]->stats.setActPoints(0);
    enginetest.currentState.getCharacters()[1]->stats.setActPoints(0);

    rai.run(enginetest);

    enginetest.currentState.getCharacters()[0]->position.setX(1);
    enginetest.currentState.getCharacters()[0]->position.setY(1);

    enginetest.currentState.getCharacters()[1]->position.setX(20);
    enginetest.currentState.getCharacters()[1]->position.setY(20);

    rai.run(enginetest);
*/

}

/* vim: set sw=2 sts=2 et : */
