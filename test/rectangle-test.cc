#include "test.h"


TEST_CASE( "Rectangle" )
{
	using namespace spot::math;
	auto r = Rectangle();
	REQUIRE( r == Rectangle::zero );
}
