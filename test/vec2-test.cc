#include "test.h"

namespace spot::math
{


TEST_CASE( "Vec2" )
{
	auto a = Vec2();
	REQUIRE( a == Vec2::Zero );

	SECTION( "Translate" )
	{
		auto matrix = Mat4::Identity;
		REQUIRE( a == matrix * a );
		REQUIRE( a == Vec2::Zero );

		matrix.translate_x( 1.0f );
		matrix.translate_y( 1.0f );
		a = matrix * a;
		REQUIRE( a == Vec2::One );
	}
}


} // namespace spot::math
