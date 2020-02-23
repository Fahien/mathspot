#include "test.h"


TEST_CASE( "Size" )
{
	using namespace spot::math;

	auto len = Size();
	REQUIRE( len == Size::null );
}
