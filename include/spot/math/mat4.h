#pragma once

#include "spot/math/math.h"
#include "spot/math/shape.h"


namespace spot::math
{


class Mat4
{
  public:
	static const Mat4 Zero;
	static const Mat4 Identity;

	Mat4() = default;
	Mat4( std::initializer_list<float> l );
	Mat4( const float* const m );
	Mat4( const Quat& quat );

	float&       operator()( size_t index );
	const float& operator()( size_t index ) const;
	float&       operator()( size_t row, size_t column );
	const float& operator()( size_t row, size_t column ) const;
	const float* operator[]( size_t index ) const;
	float* operator[]( size_t index );
	Mat4&        operator=( const Mat4& matrix );
	Mat4&        operator+=( const Mat4& matrix );
	Mat4   operator+( const Mat4& other ) const;
	Mat4&        operator*=( const Mat4& matrix );
	Mat4   operator*( const Mat4& other ) const;
	Vec3 operator*( const Vec3& v ) const;
	Vec2 operator*( const Vec2& v ) const;
	Rect operator*( const Rect& r ) const;

	bool operator==( const Mat4& other ) const;

	Vec3 get_translation() const;
	Mat4& translate( const Vec3& vec );
	void translate_x( float amount );
	void translate_y( float amount );
	void translate_z( float amount );

	Mat4 translate( const Vec3& vec ) const;
	Mat4 translate_x( float amount ) const;
	Mat4 translate_y( float amount ) const;
	Mat4 translate_z( float amount ) const;

	Mat4& scale( const Vec3& scale );
	void scale_x( float scale );
	void scale_y( float scale );
	void scale_z( float scale );

	Mat4 scale( const Vec3& scale ) const;
	Mat4 scale_x( float scale ) const;
	Mat4 scale_y( float scale ) const;
	Mat4 scale_z( float scale ) const;

	Mat4& rotate( const Quat& quat );
	void rotate_x( float radians );
	void rotate_y( float radians );
	void rotate_z( float radians );

	Mat4 rotate( const Quat& quat ) const;
	Mat4 rotate_x( float radians ) const;
	Mat4 rotate_y( float radians ) const;
	Mat4 rotate_z( float radians ) const;

	float matrix[16] = {};
};


} // namespace spot::math
