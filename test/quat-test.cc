#include "test.h"

namespace spot
{

TEST_CASE( "Quat" )
{
	using namespace spot::math;

	SECTION( "identity" )
	{
		auto q = Quat::identity;
		REQUIRE( q.w == 1.0f );
		REQUIRE( q.x == 0.0f );
		REQUIRE( q.y == 0.0f );
		REQUIRE( q.z == 0.0f );
	}

	SECTION( "from-matrix" )
	{
		auto q = Quat( Mat4::identity );
		REQUIRE( q == Quat::identity );

		SECTION( "rotation" )
		{
			SECTION( "x" )
			{
				auto rot_mat = Mat4::identity.rotateX( radians( 45.0f ) );
				auto q_from_mat = Quat( rot_mat );
				auto a = Mat4::identity.rotate( q_from_mat );
				REQUIRE( equals( rot_mat, a ) );

				rot_mat = Mat4::identity.rotateX( radians( 360.0f + 45.0f ) );
				q_from_mat = Quat( rot_mat );
				auto b = Mat4::identity.rotate( q_from_mat );
				REQUIRE( equals( rot_mat, b ) );

				REQUIRE( equals( a, b ) );
			}

			SECTION( "y" )
			{
				auto rot_mat = Mat4::identity.rotateY( radians( 45.0f ) );
				auto q_from_mat = Quat( rot_mat );
				
				auto a = Mat4::identity;
				a.rotate( q_from_mat );

				REQUIRE( equals( rot_mat, a ) );
			}

			SECTION( "z" )
			{
				auto rot_mat = Mat4::identity.rotateZ( radians( 45.0f ) );
				auto q_from_mat = Quat( rot_mat );
				
				auto a = Mat4::identity;
				a.rotate( q_from_mat );

				REQUIRE( equals( rot_mat, a ) );
			}
		}
	}
}

} // namespace spot
