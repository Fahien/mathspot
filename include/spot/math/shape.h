#pragma once

#include <vector>
#include <functional>

#include "spot/math/math.h"

namespace spot::math
{


class Rect
{
  public:
	Rect( const Vec2& a = {}, const Vec2& b = {} );

	bool operator==( const Rect& other ) const;

	Vec2 get_offset() const;
	Vec2 get_extent() const;

	/// @brief Tests whether (x, y) is inside the rectangle
	bool contains( float x, float y ) const;
	bool contains( const Vec2& p ) const;

	/// @brief Tests whether this rectangle intersects another one
	bool intersects( const Rect& other ) const;

	Vec2 a;
	Vec2 b;
};


struct Box
{
	Box( const Vec3& a = {}, const Vec3& b = {} );

	/// @brief Tests whether this box intersects another one
	bool intersects( const Box& b ) const;

	Vec3 a = {};
	Vec3 b = {};
};


struct Sphere
{
	Sphere( const Vec3& o = {}, float r = 0.0f );

	Vec3 o = {};
	float          r = 0.0f;
};


}  // namespace spot::math
