#include "test.h"


TEST_CASE( "Vec2" )
{
	using namespace spot::math;

	auto a = Vec2();
	REQUIRE( a == Vec2::zero );
}
