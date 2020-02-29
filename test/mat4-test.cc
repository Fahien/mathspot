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

	SECTION( "rotate" )
	{
		auto base = Mat4{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, -1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

		auto rot = Mat4::identity.rotateX( radians( 90.0f ) );

		for ( size_t i = 0; i < 16; ++i )
		{
			auto target = Approx( base.matrix[i] ).margin( std::numeric_limits<float>::epsilon() );
			REQUIRE( rot.matrix[i] == target );
		}
	}

	SECTION( "translate" )
	{
		auto tr = Mat4{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			2.0f, 3.0f, 4.0f, 1.0f
		};

		REQUIRE( tr == Mat4::identity.translate( { 2.0f, 3.0f, 4.0f } ) );
	}
}
