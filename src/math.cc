#include "spot/math/math.h"

#include <cmath>
#include <iostream>
#include <cassert>


namespace spot::math
{


float radians( const float degrees )
{
	return degrees * kPi / 180.0f;
}


float degrees( const float radians )
{
	return radians * 180.0f / kPi;
}


Size Size::null{};


Size::Size()
: width{ 0 }
, height{ 0 }
{
}


Size::Size( int w, int h )
: width{ w }
, height{ h }
{
}


Size& Size::operator*=( const int& f )
{
	width *= f;
	height *= f;
	return *this;
}


Size& Size::operator*=( const float& f )
{
	width  = static_cast<int>( width * f );
	height = static_cast<int>( height * f );
	return *this;
}


Size& Size::operator/=( const int& i )
{
	width /= i;
	height /= i;
	return *this;
}


const Size Size::operator/( const int& i ) const
{
	Size result = *this;
	return result /= i;
}


const bool Size::operator==( const Size& other ) const
{
	return width == other.width && height == other.height;
}


std::ostream& operator<<( std::ostream& os, const Size& s )
{
	return os << "[" << s.width << ", " << s.height << "]";
}


Vec2 Vec2::zero{};


Vec2::Vec2()
: x{ 0.0f }
, y{ 0.0f }
{
}


Vec2::Vec2( const float xx, const float yy )
: x{ xx }
, y{ yy }
{
}


void Vec2::normalize()
{
	float length = sqrtf( x * x + y * y );
	x /= length;
	y /= length;
}


Vec2& Vec2::operator=( const Vec2& other )
{
	x = other.x;
	y = other.y;
	return *this;
}


Vec2& Vec2::operator+=( const Vec2& other )
{
	x += other.x;
	y += other.y;
	return *this;
}


const Vec2 Vec2::operator+( const Vec2& other ) const
{
	Vec2 result = *this;
	return result += other;
}


const bool Vec2::operator==( const Vec2& other ) const
{
	return x == other.x && y == other.y;
}


std::ostream& operator<<( std::ostream& os, const Vec2& v )
{
	return os << "[" << v.x << ", " << v.y << "]";
}


Vec3 Vec3::zero{};


Vec3::Vec3( const float xx, const float yy, const float zz )
: x{ xx }
, y{ yy }
, z{ zz }
{
}


Vec3::Vec3( const std::vector<float>& v )
    : Vec3{ v.at( 0 ), v.at( 1 ), v.at( 2 ) }
{
}


Vec3::Vec3( const Vec3& other )
: x{ other.x }
, y{ other.y }
, z{ other.z }
{
}


Vec3::Vec3( Vec3&& other )
: x{ other.x }
, y{ other.y }
, z{ other.z }
{
}


Vec3 Vec3::cross( const Vec3& a, const Vec3& b )
{
	return {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}


float Vec3::dot( const Vec3& a, const Vec3& b )
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}


void Vec3::set( const float xx, const float yy, const float zz )
{
	x = xx;
	y = yy;
	z = zz;
}


void Vec3::normalize()
{
	float length = sqrtf( x * x + y * y + z * z );
	x /= length;
	y /= length;
	z /= length;
}


Vec3& Vec3::operator=( const Vec3& other )
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}


Vec3& Vec3::operator+=( const Vec3& other )
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}


Vec3 Vec3::operator+( const Vec3& other ) const
{
	return { x + other.x, y + other.y, z + other.z };
}


Vec3 Vec3::operator-( const Vec3& other ) const
{
	return { x - other.x, y - other.y, z - other.z };
}


Vec3 Vec3::operator-() const
{
	return { -x, -y, -z };
}


const bool Vec3::operator==( const Vec3& other ) const
{
	return x == other.x && y == other.y && z == other.z;
}


Vec3 operator*( const float c, const Vec3& v )
{
	return { c * v.x, c * v.y, c * v.z };
}


Vec3 lerp( const Vec3& a, const Vec3& b, const float t )
{
	return a + t * ( b - a );
}


std::ostream& operator<<( std::ostream& os, const Vec3& v )
{
	return os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
}


const Quat Quat::identity = { 1.0f, 0.0f, 0.0f, 0.0f };


Quat::Quat( float ww, float xx, float yy, float zz )
: w{ ww }
, x{ xx }
, y{ yy }
, z{ zz }
{
}


// [row][column]
Quat::Quat( const Mat4& matrix )
{
	float t = matrix(0,0) + matrix(1,1) + matrix(2,2);
	if ( t > 0.0f )
	{
		float s = 0.5f / sqrtf( t + 1.0f );
		w = 0.25f / s;
		x = ( matrix(2,1) - matrix(1,2) ) * s;
		y = ( matrix(0,2) - matrix(2,0) ) * s;
		z = ( matrix(1,0) - matrix(0,1) ) * s;
	}
	else
	{
		if ( matrix(0,0) > matrix(1,1) && matrix(0,0) > matrix(2,2) )
		{
			float s = 2.0f * sqrtf( 1.0f + matrix(0,0) - matrix(1,1) - matrix(2,2));
			w = (matrix(2,1) - matrix(1,2) ) / s;
			x = 0.25f * s;
			y = (matrix(0,1) + matrix(1,0) ) / s;
			z = (matrix(0,2) + matrix(2,0) ) / s;
		}
		else if (matrix(1,1) > matrix(2,2))
		{
			float s = 2.0f * sqrtf( 1.0f + matrix(1,1) - matrix(0,0) - matrix(2,2));
			w = (matrix(0,2) - matrix(2,0) ) / s;
			x = (matrix(0,1) + matrix(1,0) ) / s;
			y = 0.25f * s;
			z = (matrix(1,2) + matrix(2,1) ) / s;
		}
		else
		{
			float s = 2.0f * sqrtf( 1.0f + matrix(2,2) - matrix(0,0) - matrix(1,1) );
			w = (matrix(1,0) - matrix(0,1) ) / s;
			x = (matrix(0,2) + matrix(2,0) ) / s;
			y = (matrix(1,2) + matrix(2,1) ) / s;
			z = 0.25f * s;
		}
	}

	normalize();
}


Quat::Quat( const Vec3& axis, const float angle )
{
	auto factor = sinf( angle / 2.0f );

	x = axis.x * factor;
	y = axis.y * factor;
	z = axis.z * factor;
	w = cosf( angle / 2.0f );

	normalize();
}


bool Quat::operator==( const Quat& q ) const
{
	return w == q.w && x == q.x && y == q.y && z == q.z;
}

Quat& Quat::operator*=( const Quat& q )
{
	w = w * q.w - x * q.x - y * q.y - z * q.z;
	x = w * q.x + x * q.w - y * q.z + z * q.y;
	y = w * q.y + x * q.z + y * q.w - z * q.x;
	z = w * q.z - x * q.y + y * q.x + z * q.w;
	normalize();
	return *this;
}


Quat operator*( const float t, const Quat& q )
{
	return { t * q.w, t * q.x, t * q.y, t * q.z };
}


Quat Quat::operator-() const
{
	return -1.0f * *this;
}


Quat Quat::operator+( const Quat& o ) const
{
	return { w + o.w, x + o.x, y + o.y, z + o.z };
}


Quat Quat::operator-( const Quat& o ) const
{
	return { -o.w, -o.y, -o.z, o.x };
}


float dot( const Quat& a, const Quat& b )
{
	// Standard euclidean for product in 4D
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


float length( const Quat& q )
{
	return sqrtf( dot( q, q ) );
}


void Quat::normalize()
{
	auto len = length( *this );

	x /= len;
	y /= len;
	z /= len;
	w /= len;
}


Quat slerp( Quat a, Quat b, const float t )
{
	// Normalize a and b
	a.normalize();
	b.normalize();

	// Cosin of angle between a and b
	auto d = dot( a, b );

	// Rotate along the shortest path (-90°, 90°)
	if ( d < 0.0f )
	{
		// Reverse one quaternion
		b = -b;
		d = -d;
	}

	// Close vectors reduce to linear interpolation
	if ( d > 0.984375f )
	{
		auto r = a + t * ( b - a );
		r.normalize();
		return r;
	}

	// Find angle between a and b
	float theta_ab = acosf( d );
	// Find angle between a and result
	float theta_ar = theta_ab * t;

	float sin_theta_ab = sinf( theta_ab );
	float sin_theta_ar = sinf( theta_ar );

	float s0 = std::cos( theta_ar ) - d * sin_theta_ar / sin_theta_ab;
	float s1 = sin_theta_ar / sin_theta_ab;

	auto r = s0 * a + s1 * b;
	r.normalize();
	return r;
}


const Mat4 Mat4::zero = {};


const Mat4 Mat4::identity = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};


Mat4::Mat4()
    : matrix{ 0.0f }
{
}


Mat4::Mat4( std::initializer_list<float> list )
{
	size_t i = 0;
	for ( float value : list )
	{
		matrix[i++] = value;
		if ( i == 16 )
		{
			break;
		}
	}
}


Mat4::Mat4( const float* const m )
{
	for ( size_t i = 0; i < 16; ++i )
	{
		matrix[i] = m[i];
	}
}


Mat4::Mat4( const Quat& q )
{
	float s = 2.0f / ( q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w );

	float xs = s * q.x;
	float ys = s * q.y;
	float zs = s * q.z;

	float wx = q.w * xs;
	float wy = q.w * ys;
	float wz = q.w * zs;

	float xx = q.x * xs;
	float xy = q.x * ys;
	float xz = q.x * zs;

	float yy = q.y * ys;
	float yz = q.y * zs;
	float zz = q.z * zs;

	matrix[0]  = 1.0f - ( yy + zz );
	matrix[4]  = xy - wz;
	matrix[8]  = xz + wy;
	matrix[12] = 0.0f;

	matrix[1]  = xy + wz;
	matrix[5]  = 1.0f - ( xx + zz );
	matrix[9]  = yz - wx;
	matrix[13] = 0.0f;

	matrix[2]  = xz - wy;
	matrix[6]  = yz + wx;
	matrix[10] = 1.0f - ( xx + yy );
	matrix[14] = 0.0f;

	matrix[3]  = 0.0f;
	matrix[7]  = 0.0f;
	matrix[11] = 0.0f;
	matrix[15] = 1.0f;
}


float& Mat4::operator()( const size_t index )
{
	assert( index < 16 && "Index out of bounds" );
	return matrix[index];
}


const float& Mat4::operator()( const size_t index ) const
{
	assert( index < 16 && "Index out of bounds" );
	return matrix[index];
}


float& Mat4::operator()( const size_t row, const size_t column )
{
	assert( row < 4 && column < 4 && "Row or column out of bounds" );
	return matrix[row + 4 * column];
}


const float& Mat4::operator()( const size_t row, const size_t column ) const
{
	assert( row < 4 && column < 4 && "Row or column out of bounds" );
	return matrix[row + 4 * column];
}



const float* Mat4::operator[]( const size_t index ) const
{
	assert( index < 4 && "Index out of bounds" );
	return matrix + ( index * 4 );
}


float* Mat4::operator[]( const size_t index )
{
	assert( index < 4 && "Index out of bounds" );
	return matrix + ( index * 4 );
}


Mat4& Mat4::operator=( const Mat4& other )
{
	for ( size_t i = 0; i < 16; ++i )
	{
		matrix[i] = other.matrix[i];
	}
	return *this;
}


Mat4& Mat4::operator+=( const Mat4& other )
{
	for ( size_t i = 0; i < 16; ++i )
	{
		matrix[i] += other.matrix[i];
	}
	return *this;
}


Mat4 Mat4::operator+( const Mat4& other ) const
{
	Mat4 result = *this;
	return result += other;
}


Mat4& Mat4::operator*=( const Mat4& other )
{
	float temp[16];
	for ( size_t i = 0; i < 4; ++i )
	{
		for ( size_t j = 0; j < 4; ++j )
		{
			temp[i + j * 4] = matrix[i] * other.matrix[j * 4] + matrix[i + 4] * other.matrix[j * 4 + 1] +
			                  matrix[i + 8] * other.matrix[j * 4 + 2] + matrix[i + 12] * other.matrix[j * 4 + 3];
		}
	}
	for ( int i = 0; i < 16; ++i )
	{
		matrix[i] = temp[i];
	}
	return *this;
}


Mat4 Mat4::operator*( const Mat4& other ) const
{
	Mat4 result = *this;
	return result *= other;
}


Vec3 Mat4::operator*( const Vec3& v ) const
{
	float ret[4] = {};
	for ( auto i = 0; i < 4; ++i )
	{
		for ( auto j = 0; j < 3; ++j )
		{
			auto vv = ( &( v.x ) )[j];
			auto mv =  matrix[i + j * 4];
			ret[i] += mv * vv;
		}
		auto mv = matrix[i + 3 * 4];
		ret[i] += mv;
	}

	return { ret[0] / ret[3], ret[1] / ret[3], ret[2] / ret[3] };
}


bool Mat4::operator==( const Mat4& other ) const
{
	for ( auto i = 0; i < 16; ++i )
	{
		if ( matrix[i] != other.matrix[i] )
		{
			return false;
		}
	}
	return true;
}


void Mat4::translate( const Vec3& vec )
{
	matrix[12] += vec.x;
	matrix[13] += vec.y;
	matrix[14] += vec.z;
}


void Mat4::translateX( const float amount )
{
	matrix[12] += amount;
}


void Mat4::translateY( const float amount )
{
	matrix[13] += amount;
}


void Mat4::translateZ( const float amount )
{
	matrix[14] += amount;
}


void Mat4::scale( const Vec3& scale )
{
	matrix[0]  = scale.x;
	matrix[5]  = scale.y;
	matrix[10] = scale.z;
}


Mat4 Mat4::scale( const Vec3& scale ) const
{
	auto ret = *this;
	ret.scale( scale );
	return ret;
}


void Mat4::scaleX( const float scale )
{
	matrix[0] = scale;
}


void Mat4::scaleY( const float scale )
{
	matrix[5] = scale;
}


void Mat4::scaleZ( const float scale )
{
	matrix[10] = scale;
}


void Mat4::rotate( const Quat& q )
{
	float xw, yw, zw, xx, yy, yz, xy, xz, zz;

	xx = q.x * q.x;
	xy = q.x * q.y;
	xz = q.x * q.z;
	xw = q.x * q.w;

	yy = q.y * q.y;
	yz = q.y * q.z;
	yw = q.y * q.w;

	zz = q.z * q.z;
	zw = q.z * q.w;

	Mat4 rot {
		1.0f - 2.0f * ( yy + zz ),
		2.0f * ( xy - zw ),
		2.0f * ( xz + yw ),
		0.0f,  // row1
		2.0f * ( xy + zw ),
		1.0f - 2.0f * ( xx + zz ),
		2.0f * ( yz - xw ),
		0.0f,  // row2
		2.0f * ( xz - yw ),
		2.0f * ( yz + xw ),
		1.0f - 2.0f * ( xx + yy ),
		0.0f,  // row3
		0.0f,
		0.0f,
		0.0f,
		1.0f,  // row4
	};

	*this = rot * *this;
}


void Mat4::rotateX( const float radians )
{
	float cosrad = std::cos( radians );
	float sinrad = std::sin( radians );
	Mat4 rotation{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosrad, sinrad, 0.0f,
		0.0f, -sinrad, cosrad, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f };
	*this = rotation * *this;
}


void Mat4::rotateY( const float radians )
{
	float cosrad = std::cos( radians );
	float sinrad = std::sin( radians );
	Mat4 rotation {
		cosrad, 0.0f, -sinrad, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		sinrad, 0.0f, cosrad, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f };
	*this = rotation * *this;
}


void Mat4::rotateZ( const float radians )
{
	float cosrad = std::cos( radians );
	float sinrad = std::sin( radians );
	Mat4 rotation {
		cosrad, sinrad, 0.0f, 0.0f,
		-sinrad, cosrad, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f };
	*this = rotation * *this;
}


Rectangle Rectangle::zero{};


Rectangle::Rectangle()
: x{ 0.0f }
, y{ 0.0f }
, width{ 0.0f }
, height{ 0.0f }
{
}


const bool Rectangle::operator==( const Rectangle& other ) const
{
	return x == 0.0f && y == 0.0f && width == 0.0f && height == 0.0f;
}


bool Rectangle::contains( float xx, float yy )
{
	return ( x <= xx && xx <= ( x + width ) ) && ( y <= yy && yy <= ( y + height ) );
}


bool Rectangle::intersects( const Rectangle& other )
{
	return ( fabs( x - other.x ) * 2 < ( width + other.width ) ) && ( fabs( y - other.y ) * 2 < ( height + other.height ) );
}


bool Rectangle::intersects( const Rectangle* other )
{
	return ( fabs( x - other->x ) * 2 < ( width + other->width ) ) &&
	       ( fabs( y - other->y ) * 2 < ( height + other->height ) );
}


}  // namespace spot::math
