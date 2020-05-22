#include "test.h"

namespace spot::math
{


bool equals( const float a, const float b )
{
		auto target = Approx( a ).margin( std::numeric_limits<float>::epsilon() * 2.0f );
		return b == target;
}


bool equals( const Quat& a, const Quat& b )
{
	return equals( a.w, b.w ) &&
		equals( a.x, b.x ) &&
		equals( a.y, b.y ) &&
		equals( a.z, b.z );
}


TEST_CASE( "Quat" )
{
	SECTION( "identity" )
	{
		auto q = Quat::Identity;
		REQUIRE( q.w == 1.0f );
		REQUIRE( q.x == 0.0f );
		REQUIRE( q.y == 0.0f );
		REQUIRE( q.z == 0.0f );
	}

	SECTION( "from-axis-angle" )
	{
		auto q = Quat::Identity;
		auto angle = radians( 90.0f );

		q *= Quat( Vec3::Z, radians( 90.0f ) );

		auto expected = Quat( Mat4::Identity.rotate_z( angle ) );

		REQUIRE( equals( q, expected ) );
	}

	SECTION( "from-matrix" )
	{
		auto q = Quat( Mat4::Identity );
		REQUIRE( q == Quat::Identity );

		SECTION( "rotation" )
		{
			SECTION( "x" )
			{
				auto rot_mat = Mat4::Identity.rotate_x( radians( 45.0f ) );
				auto q_from_mat = Quat( rot_mat );
				auto a = Mat4::Identity.rotate( q_from_mat );
				REQUIRE( equals( rot_mat, a ) );

				rot_mat = Mat4::Identity.rotate_x( radians( 360.0f + 45.0f ) );
				q_from_mat = Quat( rot_mat );
				auto b = Mat4::Identity.rotate( q_from_mat );
				REQUIRE( equals( rot_mat, b ) );

				REQUIRE( equals( a, b ) );
			}

			SECTION( "y" )
			{
				auto rot_mat = Mat4::Identity.rotate_y( radians( 45.0f ) );
				auto q_from_mat = Quat( rot_mat );
				
				auto a = Mat4::Identity;
				a.rotate( q_from_mat );

				REQUIRE( equals( rot_mat, a ) );
			}

			SECTION( "z" )
			{
				auto rot_mat = Mat4::Identity.rotate_z( radians( 45.0f ) );
				auto q_from_mat = Quat( rot_mat );
				
				auto a = Mat4::Identity;
				a.rotate( q_from_mat );

				REQUIRE( equals( rot_mat, a ) );
			}
		}
	}
}


} // namespace spot::math
