#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Element.h"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestStateClasses)

{
    //Element test
    {
    Element myElement ;

    BOOST_CHECK_EQUAL(myElement.isMapCell(),true);

    }
    

}