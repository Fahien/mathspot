#pragma once

#include <vector>
#include <functional>

#include "spot/math/math.h"

namespace spot::math
{


/// @todo Would it be better to use a vector origin point?
class Rect
{
  public:
	static const Rect Unit;

	/// @brief Default constructs a degenerate rect centered at the origin
	constexpr Rect( const Vec2& aa = {}, const Vec2& bb = {} ) : a { aa }, b { bb } {}

	Rect& operator*=( float c );
	Rect operator*( float c ) const;

	bool operator==( const Rect& other ) const;

	Vec2 get_offset() const;
	Vec2 get_extent() const;

	/// @brief Tests whether (x, y) is inside the rectangle
	bool contains( float x, float y ) const;
	bool contains( const Vec2& p ) const;

	/// @brief Tests whether this rectangle intersects another one
	bool intersects( const Rect& other ) const;

	/// @return The X distance from another rectangle
	float distance_x( const Rect& other ) const;

	/// @return The Y distance from another rectangle
	float distance_y( const Rect& other ) const;

	/// @return The distance from another rectangle
	Vec2 distance( const Rect& other ) const;

	Vec2 a;
	Vec2 b;
};


struct Box
{
	/// @brief Default constructs degenerate box centered at the origin
	constexpr Box( const Vec3& aa = {}, const Vec3& bb = {} ) : a { aa }, b { bb } {}

	/// @brief Tests whether this box intersects another one
	bool intersects( const Box& b ) const;

	Vec3 a;
	Vec3 b;
};


struct Sphere
{
	/// @brief Default constructs a degenerate sphere centered at the origin
	constexpr Sphere( const Vec3& oo = {}, float rr = 0.0f ) : o { oo }, r { rr } {}

	Vec3 o;
	float r;
};


}  // namespace spot::math
