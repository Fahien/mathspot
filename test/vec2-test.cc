#include "test.h"

namespace spot::math
{


TEST_CASE( "Vec2" )
{
	auto a = Vec2();
	REQUIRE( a == Vec2::Zero );

	SECTION( "Translate" )
	{
		auto matrix = Mat4::identity;
		REQUIRE( a == matrix * a );
		REQUIRE( a == Vec2::Zero );

		matrix.translateX( 1.0f );
		matrix.translateY( 1.0f );
		a = matrix * a;
		REQUIRE( a == Vec2::One );
	}
}


} // namespace spot::math
