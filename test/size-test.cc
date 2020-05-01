#include "test.h"

namespace spot::math
{


TEST_CASE( "Size" )
{

	auto len = Size();
	REQUIRE( len == Size::Null );
}


} // namespace spot::math
