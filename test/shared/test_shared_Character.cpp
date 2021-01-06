#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../../src/shared/state/Character.h"
#include "../../src/shared/state/State.h"
#include "../../src/client/render.h"

using namespace ::state;
using namespace ::std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
  
    Spells mySpellSet;
    Character c1{PLAYER, "Hamzalemsnap", 0, 0, mySpellSet,1,302};
    Character c2{BOWMAN, "Rachidox", 5, 5, mySpellSet,1,303};
    Character c3{SKELETON, "Lepo", 10, 10, mySpellSet,1,302};
    Character c4{SORCERER, "Abdoulaye", 15, 15, mySpellSet,1,302};

    BOOST_CHECK_EQUAL(c1.getType(), PLAYER);
    BOOST_CHECK_EQUAL(c1.getStats().health, 150);

    c1.stats.setExperience(100);
    c1.LevelUp();
    BOOST_CHECK_EQUAL(c1.getStats().getLevel(), 2);
    BOOST_CHECK_EQUAL(c1.getSpells().getDamage(), 20);
    BOOST_CHECK(!c1.isMapCell());

    BOOST_CHECK_EQUAL(c1.getStatus(), FIGHTING);
    c1.setStatus(WAITING);
    BOOST_CHECK_EQUAL(c1.getStatus(), WAITING);

    std::vector<Position> posi;
    std::vector<int> vec;
    State s{"ok"};
    s.initializeCharacters();
    
    vec=s.characters[0].get()->verifAttackPosition(s);
    BOOST_CHECK_EQUAL(vec[0], 1);


}

