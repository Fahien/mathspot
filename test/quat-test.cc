#include "test.h"


TEST_CASE( "Quat" )
{
	using namespace spot::math;

	SECTION( "identity" )
	{
		auto q = Quat::identity;
		REQUIRE( q.w == 1.0f );
		REQUIRE( q.x == 0.0f );
		REQUIRE( q.y == 0.0f );
		REQUIRE( q.z == 0.0f );
	}

	SECTION( "from-matrix" )
	{
		auto q = Quat( Mat4::identity );
		REQUIRE( q == Quat::identity );
	}
}
