#include "test.h"
#include "spot/math/shape.h"

namespace spot::math
{


TEST_CASE( "Rect" )
{
	auto r = Rect( Vec2::Zero, Vec2::One );
	REQUIRE( r.contains( 0.5f, 0.4f ) );
	REQUIRE( !r.contains( 1.1f, 2.2f ) );
}


} // namespace spot::math
