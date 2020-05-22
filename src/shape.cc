#include "spot/math/shape.h"

#include <cmath>
#include <algorithm>

namespace spot::math
{


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
	return abs( b - a );
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
	return offset.x < ( other_offset.x + other_extent.x ) &&
		( offset.x + extent.x ) > other_offset.x &&
		( offset.y + extent.y ) > other_offset.y &&
		offset.y < ( other_offset.y + other_extent.y );
}


float Rect::distance_x( const Rect& other ) const
{
	if ( a.x < other.a.x )
	{
		return ( other.a.x - a.x ) - ( b.x - a.x );
	}
	else
	{
		return ( other.a.x - a.x ) + ( other.b.x - other.a.x );
	}
}


float Rect::distance_y( const Rect& other ) const
{
	if ( a.y < other.a.y )
	{
		return ( other.a.y - a.y ) - ( b.y - a.y );
	}
	else
	{
		return ( other.a.y - a.y ) + ( other.b.y - other.a.y );
	}
}


Vec2 Rect::distance( const Rect& other ) const
{
	return { distance_x( other ), distance_y( other ) };
}


bool Box::intersects( const Box& other ) const
{
	/// @todo add depth
	return a.x < other.b.x && b.x > other.a.x && b.y > other.a.y && a.y < other.b.y;
}


}  // namespace spot::math
