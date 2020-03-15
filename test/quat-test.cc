#include "test.h"

namespace spot
{


bool equals( const float a, const float b )
{
		auto target = Approx( a ).margin( std::numeric_limits<float>::epsilon() * 2.0f );
		return b == target;
}


bool equals( const math::Quat& a, const math::Quat& b )
{
	return equals( a.w, b.w ) &&
		equals( a.x, b.x ) &&
		equals( a.y, b.y ) &&
		equals( a.z, b.z );
}


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

	SECTION( "from-axis-angle" )
	{
		auto q = Quat::identity;
		auto angle = radians( 90.0f );

		q *= Quat( Vec3::Z, radians( 90.0f ) );

		auto expected = Quat( Mat4::identity.rotateZ( angle ) );

		REQUIRE( equals( q, expected ) );
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
