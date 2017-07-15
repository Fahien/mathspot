#include <cmath>

#include "MathSpot.h"


namespace mst = mathspot;


mst::Size::Size()
	: width { 0 }
	, height{ 0 }
{}


mst::Size::Size(int w, int h)
	: width { w }
	, height{ h }
{}


mst::Size & mst::Size::operator *= (const int & f)
{
	width  *= f;
	height *= f;
	return *this;
}


mst::Size & mst::Size::operator *= (const float & f)
{
	width  = static_cast<int>(width * f);
	height = static_cast<int>(height * f);
	return *this;
}


mst::Size & mst::Size::operator /= (const int & i)
{
	width  /= i;
	height /= i;
	return *this;
}


std::ostream & mst::operator << (std::ostream & os, const mst::Size & s)
{
	return os << "[" << s.width << ", " << s.height << "]";
}


const mst::Size mst::Size::operator / (const int & i) const
{
	mst::Size result = *this;
	return result /= i;
}


mst::Vec2::Vec2()
	: x{ 0.0f }
	, y{ 0.0f }
{}


mst::Vec2::Vec2(const float xx, const float yy)
	: x{ xx }
	, y{ yy }
{}


void mst::Vec2::normalize()
{
	float length{ sqrtf(x * x + y * y) };
	x /= length;
	y /= length;
}


mst::Vec2 & mst::Vec2::operator = (const mst::Vec2 & other)
{
	x = other.x;
	y = other.y;
	return *this;
}


mst::Vec2 & mst::Vec2::operator += (const mst::Vec2 & other)
{
	x += other.x;
	y += other.y;
	return *this;
}


const mst::Vec2 mst::Vec2::operator + (const mst::Vec2 & other) const
{
	mst::Vec2 result = *this;
	return result += other;
}


std::ostream & mst::operator<<(std::ostream & os, const Vec2 & v)
{
	return os << "[" << v.x << ", " << v.y << "]";
}


mst::Vec3::Vec3()
	: x{ 0.0f }
	, y{ 0.0f }
	, z{ 0.0f }
{}


mst::Vec3::Vec3(const float xx, const float yy, const float zz)
	: x{ xx }
	, y{ yy }
	, z{ zz }
{}


mst::Vec3 mst::Vec3::cross(const mst::Vec3 & a, const mst::Vec3 & b)
{
	mst::Vec3 result{};
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}


void mst::Vec3::normalize()
{
	float length{ sqrtf(x * x + y * y + z * z) };
	x /= length;
	y /= length;
	z /= length;
}


mst::Vec3 & mst::Vec3::operator = (const mst::Vec3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}


mst::Vec3 & mst::Vec3::operator += (const mst::Vec3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}


std::ostream &mst::operator << (std::ostream & os, const mst::Vec3 & v)
{
	return os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
}


mst::Mat4 mst::Mat4::identity
{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};


mst::Mat4::Mat4()
	: matrix{ 0.0f }
{}


mst::Mat4::Mat4(std::initializer_list<float> list)
{
	int i{ 0 };
	for (float value : list)
	{
		matrix[i] = value;
		++i;
		if (i == 16) { break; }
	}
}


mst::Mat4::Mat4(const float * const m)
{
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] = m[i];
	}
}


float & mst::Mat4::operator [] (const int index)
{
	return matrix[index];
}


float mst::Mat4::operator [] (const int index) const
{
	return matrix[index];
}


mst::Mat4 & mst::Mat4::operator  =(const mst::Mat4 & other)
{
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] = other.matrix[i];
	}
	return *this;
}


mst::Mat4 & mst::Mat4::operator += (const mst::Mat4 & other)
{
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] += other.matrix[i];
	}
	return *this;
}


const mst::Mat4 mst::Mat4::operator + (const mst::Mat4 & other) const
{
	mst::Mat4 result = *this;
	return result += other;
}


mst::Mat4 & mst::Mat4::operator *= (const mst::Mat4 & other)
{
	float temp[16];
	for (int i{ 0 }; i < 4; ++i)
	{
		for (int j{ 0 }; j < 4; ++j)
		{
			temp[i + j * 4] = matrix[i]      * other[j * 4] +
			                  matrix[i + 4]  * other[j * 4 + 1] +
			                  matrix[i + 8]  * other[j * 4 + 2] +
			                  matrix[i + 12] * other[j * 4 + 3];
		}
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] = temp[i];
	}
	return *this;
}


const mst::Mat4 mst::Mat4::operator * (const mst::Mat4 & other) const
{
	Mat4 result = *this;
	return result *= other;
}


void mst::Mat4::translateX(const float amount)
{
	matrix[12] += amount;
}


void mst::Mat4::translateY(const float amount)
{
	matrix[13] += amount;
}


void mst::Mat4::translateZ(const float amount)
{
	matrix[14] += amount;
}


void mst::Mat4::rotateX(const float radians)
{
	float cosrad{ static_cast<float>(std::cos(radians)) };
	float sinrad{ static_cast<float>(std::sin(radians)) };
	mst::Mat4 rotation
	{
		1.0f, 0.0f,    0.0f,   0.0f,
		0.0f, cosrad,  sinrad, 0.0f,
		0.0f, -sinrad, cosrad, 0.0f,
		0.0f, 0.0f,    0.0f,   1.0f
	};
	*this = rotation * *this;
}


void mst::Mat4::rotateY(const float radians)
{
	float cosrad{ static_cast<float>(std::cos(radians)) };
	float sinrad{ static_cast<float>(std::sin(radians)) };
	mst::Mat4 rotation
	{
		cosrad, 0.0f, -sinrad, 0.0f,
		0.0f,   1.0f, 0.0f,    0.0f,
		sinrad, 0.0f, cosrad,  0.0f,
		0.0f,   0.0f, 0.0f,    1.0f
	};
	*this = rotation * *this;
}


void mst::Mat4::rotateZ(const float radians)
{
	float cosrad{ static_cast<float>(std::cos(radians)) };
	float sinrad{ static_cast<float>(std::sin(radians)) };
	mst::Mat4 rotation
	{
		cosrad,  sinrad, 0.0f, 0.0f,
		-sinrad, cosrad, 0.0f, 0.0f,
		0.0f,    0.0f,   1.0f, 0.0f,
		0.0f,    0.0f,   0.0f, 1.0f
	};
	*this = rotation * *this;
}


mst::Rectangle::Rectangle()
	: x     { 0.0f }
	, y     { 0.0f }
	, width { 0.0f }
	, height{ 0.0f }
{}


bool mst::Rectangle::contains(float xx, float yy)
{
	return (x <= xx && xx <= (x + width) && y <= yy && yy <= (y + height));
}


bool mst::Rectangle::intersects(const mst::Rectangle & other)
{
	return (fabs(x - other.x) * 2 < (width + other.width)) &&
	       (fabs(y - other.y) * 2 < (height + other.height));
}

bool mst::Rectangle::intersects(const Rectangle * other)
{
	return (fabs(x - other->x) * 2 < (width + other->width)) &&
	       (fabs(y - other->y) * 2 < (height + other->height));
}
