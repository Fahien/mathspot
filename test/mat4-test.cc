#include "test.h"


namespace spot::math
{

bool equals( const Mat4& a, const Mat4& b )
{
	for ( size_t i = 0; i < 16; ++i )
	{
		auto target = Approx( a.matrix[i] ).margin( std::numeric_limits<float>::epsilon() * 2.0f );
		if ( b.matrix[i] != target )
		{
			return false;
		}
	}

	return true;
}


TEST_CASE( "Mat4" )
{
	SECTION( "zero" )
	{
		auto a = Mat4();
		REQUIRE( a == Mat4::Zero );
	}

	SECTION( "identity" )
	{
		auto id = Mat4{
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

		REQUIRE( id == Mat4::Identity );
	}

	SECTION( "scale" )
	{
		auto sc = Mat4{
			2.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 2.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};

		REQUIRE( sc == Mat4::Identity.scale( { 2.0f, 2.0f, 2.0f } ) );
	}

	SECTION( "rotate" )
	{
		SECTION( "x" )
		{
			auto base = Mat4{
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, -1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			};

			auto rot = Mat4::Identity.rotateX( radians( 90.0f ) );
			REQUIRE( equals( base, rot ) );

			auto double_rot = Mat4::Identity.rotateX( radians( 360.0f + 90.0f ) );
			REQUIRE( equals( base, double_rot ) );

			base = Mat4{
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.7071068f, 0.7071068f, 0.0f,
				0.0f, -0.7071068f, 0.7071068f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			};

			rot = Mat4::Identity.rotateX( radians( 45.0f ) );
			REQUIRE( equals( base, rot ) );
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

		REQUIRE( tr == Mat4::Identity.translate( { 2.0f, 3.0f, 4.0f } ) );
	}
}


} // namespace spot::math
