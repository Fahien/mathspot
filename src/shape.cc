#include "spot/math/shape.h"

#include <cmath>
#include <algorithm>

namespace spot::math
{


Rect::Rect( const Vec2& aa, const Vec2& bb )
: a { aa }
, b { bb }
{}


bool Rect::operator==( const Rect& other ) const
{
	return a == other.a && b == other.b;
}


Vec2 Rect::get_offset() const
{
	return { std::min( a.x, b.x ), std::min( a.y, b.y ) };
}


Vec2 Rect::get_extent() const
{
	return { std::fabs( a.x - b.x ), std::fabs( a.y - b.y ) };
}


bool Rect::contains( const float xx, const float yy ) const
{
	auto offset = get_offset();
	auto extent = get_extent();
	return ( offset.x <= xx && xx <= ( offset.x + extent.x ) ) && ( offset.y <= yy && yy <= ( offset.y + extent.y ) );
}


bool Rect::contains( const Vec2& p ) const
{
	return contains( p.x, p.y );
}



bool Rect::intersects( const Rect& other ) const
{
	auto offset = get_offset();
	auto extent = get_extent();
	auto other_offset = other.get_offset();
	auto other_extent = other.get_extent();
	return ( fabs( offset.x - other_offset.x ) * 2 < ( extent.x + other_extent.x ) ) &&
	       ( fabs( offset.y - other_offset.y ) * 2 < ( extent.y + other_extent.y ) );
}


Box::Box( const Vec3& aa, const Vec3& bb )
: a { aa }
, b { bb }
{
}


bool Box::intersects( const Box& other ) const
{
	/// @todo add depth
	return a.x < other.b.x && b.x > other.a.x && b.y > other.a.y && a.y < other.b.y;
}


Sphere::Sphere( const Vec3& oo, const float rr )
: o { oo }
, r { rr }
{
}


}  // namespace spot::math
