#include "test.h"

namespace spot::math
{


TEST_CASE( "Misc" )
{
	SECTION( "radians" )
	{
		REQUIRE( radians( 90.0f ) == kPi / 2.0f );
		REQUIRE( radians( 180.0f ) == kPi );
		REQUIRE( radians( 360.0f ) == kPi * 2.0f );
		REQUIRE( radians( 540.0f ) == kPi * 3.0f );
	}

	SECTION( "degrees" )
	{
		REQUIRE( degrees( kPi / 2.0f ) == 90.0f );
		REQUIRE( degrees( kPi ) == 180.0f );
		REQUIRE( degrees( kPi * 2.0f ) == 360.0f );
		REQUIRE( degrees( kPi * 3.0f ) == 540.0f );
	}
}


} // namespace spot::math
