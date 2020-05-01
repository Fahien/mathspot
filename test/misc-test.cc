#include "test.h"

namespace spot::math
{


TEST_CASE( "Misc" )
{
	SECTION( "radians" )
	{
		REQUIRE( radians( 90.0f ) == Pi / 2.0f );
		REQUIRE( radians( 180.0f ) == Pi );
		REQUIRE( radians( 360.0f ) == Pi * 2.0f );
		REQUIRE( radians( 540.0f ) == Pi * 3.0f );
	}

	SECTION( "degrees" )
	{
		REQUIRE( degrees( Pi / 2.0f ) == 90.0f );
		REQUIRE( degrees( Pi ) == 180.0f );
		REQUIRE( degrees( Pi * 2.0f ) == 360.0f );
		REQUIRE( degrees( Pi * 3.0f ) == 540.0f );
	}
}


} // namespace spot::math
