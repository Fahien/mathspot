#include "spot/math/shape.h"

#include <cmath>
#include <algorithm>

namespace spot::math
{


Rect::Rect( const Vec2& a, const Vec2& b )
: offset { a }
, extent { b.x - a.x, b.y - a.y }
{
	assert( a.x < b.x && "Point a should be left of point b" );
	assert( a.y < b.y && "Point a should be below point b" );
}


bool Rect::operator==( const Rect& other ) const
{
	return offset.x == other.offset.x && offset.y == other.offset.y &&
	       extent.x == other.extent.x && extent.y == other.extent.y;
}


bool Rect::contains( const float xx, const float yy ) const
{
	return ( offset.x <= xx && xx <= ( offset.x + extent.x ) ) && ( offset.y <= yy && yy <= ( offset.y + extent.y ) );
}


bool Rect::contains( const Vec2& p ) const
{
	return contains( p.x, p.y );
}



bool Rect::intersects( const Rect& other ) const
{
	return ( fabs( offset.x - other.offset.x ) * 2 < ( extent.x + other.extent.x ) ) &&
	       ( fabs( offset.y - other.offset.y ) * 2 < ( extent.y + other.extent.y ) );
}


Box::Box( const Vec3& aa, const Vec3& bb )
: a { aa }
, b { bb }
{
}


bool Box::intersects( const Box& other ) const
{
	// TODO add depth
	return a.x < other.b.x && b.x > other.a.x && b.y > other.a.y && a.y < other.b.y;
}


Sphere::Sphere( const Vec3& oo, const float rr )
: o { oo }
, r { rr }
{
}


}  // namespace spot::gltf
