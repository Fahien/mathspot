#include "test.h"



TEST_CASE( "Vec3" )
{
	using namespace spot::math;

	auto a = Vec3();
	REQUIRE( a == Vec3::Zero );

	auto b = Vec3( 1.0f, 2.0f, 3.0f );
	a += b;
	REQUIRE( a == b );

	a.set( -1.0f, -2.0f, -3.0f );
	REQUIRE( a == -b );

	auto c = Vec3::cross( a, b );
	REQUIRE( c == Vec3::Zero );
}
