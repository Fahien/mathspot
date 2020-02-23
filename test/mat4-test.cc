#include "test.h"


TEST_CASE( "Mat4" )
{
	using namespace spot::math;

	SECTION( "zero" )
	{
		auto a = Mat4();
		REQUIRE( a == Mat4::zero );
	}

	SECTION( "identity" )
	{
		auto id = Mat4{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

		REQUIRE( id == Mat4::identity );
	}

	SECTION( "scale" )
	{
		auto sc = Mat4{
			2.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 2.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

		REQUIRE( sc == Mat4::identity.scale( { 2.0f, 2.0f, 2.0f } ) );
	}
}
