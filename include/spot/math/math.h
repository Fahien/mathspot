#pragma once

#include <iostream>
#include <vector>


namespace spot::math
{


constexpr float Pi = 3.14159265f;


/// Degrees to radians conversion
/// @param[in] degrees Angle in degrees
/// @return Angle in radians
constexpr float radians( const float degrees )
{
	return degrees * Pi / 180.0f;
}


/// Radians to degrees conversion
/// @param[in] radians Angle in radians
/// @return Angle in degrees
constexpr float degrees( const float radians )
{
	return radians * 180.0f / Pi;
}


class Size
{
  public:
	static const Size Null;

	Size( uint64_t w = 0, uint64_t h = 0 );

	Size&      operator*=( const uint64_t f );
	Size&      operator*=( const float f );
	Size&      operator/=( const uint64_t i );
	const Size operator/( const uint64_t i ) const;

	bool operator==( const Size& other ) const;

	friend std::ostream& operator<<( std::ostream& os, const Size& v );

	uint64_t width;
	uint64_t height;
};


class Vec2
{
  public:
	static const Vec2 Zero;
	static const Vec2 One;

	constexpr Vec2( float xx = 0.0f, float yy = 0.0f ) : x { xx }, y { yy } {}

	void normalize();

	Vec2& operator=( const Vec2& other );
	Vec2& operator+=( const Vec2& other );
	Vec2& operator-=( const Vec2& other );
	Vec2& operator*=( const Vec2& other );
	Vec2& operator*=( float c );
	Vec2& operator/=( float c );
	Vec2 operator+( const Vec2& other ) const;
	Vec2 operator-( const Vec2& other ) const;
	Vec2 operator-() const;
	Vec2 operator*( const Vec2& other ) const;
	Vec2 operator*( float c ) const;
	Vec2 operator/( float c ) const;

	bool operator==( const Vec2& other ) const;
	bool operator!=( const Vec2& other ) const;

	friend std::ostream& operator<<( std::ostream& os, const Vec2& v );

	float x = 0.0f;
	float y = 0.0f;
};


Vec2 abs( const Vec2& v );


class Vec3
{
  public:
	static const Vec3 Zero;
	static const Vec3 One;
	static const Vec3 X;
	static const Vec3 Y;
	static const Vec3 Z;

	constexpr Vec3( float xx = 0.0f, float yy = 0.0f, float zz = 0.0f )
	: x { xx }, y { yy }, z{ zz }
	{}

	constexpr Vec3( const Vec2& vv )
	: Vec3( vv.x, vv.y )
	{}

	static Vec3 cross( const Vec3& a, const Vec3& b );
	static float dot( const Vec3& a, const Vec3& b );

	void set( float xx, float yy, float zz );
	void normalize();

	Vec3& operator=( const Vec2& other );

	Vec3& operator+=( const Vec3& other );
	Vec3& operator+=( const Vec2& other );
	Vec3& operator+=( float c );
	Vec3 operator+( const Vec3& other ) const;
	Vec3 operator-( const Vec3& other ) const;
	Vec3 operator-() const;

	Vec3& operator*=( const Vec3& other );
	Vec3 operator*( const Vec3& other ) const;

	Vec3& operator*=( float k );
	Vec3 operator*( float k ) const;
	Vec3& operator/=( float k );
	Vec3 operator/( float k ) const;

	bool operator==( const Vec3& other ) const;
	bool operator!=( const Vec3& other ) const;

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

Vec3 operator*( float c, const Vec3& v );

Vec3 lerp( const Vec3& a, const Vec3& b, const float t );

std::ostream& operator<<( std::ostream& os, const Vec3& v );

class Mat4;


class Quat
{
  public:
	static const Quat Identity;

	Quat( float w = 0.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f );

	Quat( const Mat4& m );

	/// @brief Constructs a quaternion from an axis
	/// and an angle of rotation around that axis
	Quat( const Vec3& axis, float radians );

	void normalize();

	bool operator==( const Quat& other ) const;

	/// @brief A multiplication of two quaternions is
	/// just the composition of the two quaternions
	Quat& operator*=( const Quat& other );

	Quat operator-() const;

	Quat& operator+=( const Quat& other );
	Quat operator+( const Quat& other ) const;
	Quat operator-( const Quat& other ) const;

	float w = 0.0f;
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

Quat operator*( float c, const Quat& q );

float dot( const Quat& a, const Quat& b );

float length( const Quat& q );

Quat slerp( Quat a, Quat b, float t );



}  // namespace spot::math
