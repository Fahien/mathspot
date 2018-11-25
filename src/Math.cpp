#include <cmath>

#include "mathspot/Math.h"


using namespace mathspot;


float mathspot::radians(const float degrees)
{
	return degrees * kPi / 180.0f;
}


float mathspot::degrees(const float radians)
{
	return radians * 180.0f / kPi;
}


Size Size::null{};


Size::Size()
:	width { 0 }
,	height{ 0 }
{}


Size::Size(int w, int h)
:	width { w }
,	height{ h }
{}


Size& Size::operator*=(const int& f)
{
	width  *= f;
	height *= f;
	return *this;
}


Size& Size::operator*=(const float& f)
{
	width  = static_cast<int>(width  * f);
	height = static_cast<int>(height * f);
	return *this;
}


Size& Size::operator/=(const int& i)
{
	width  /= i;
	height /= i;
	return *this;
}


const Size Size::operator/(const int& i) const
{
	Size result = *this;
	return result /= i;
}


const bool Size::operator==(const Size& other) const
{
	return width == other.width && height == other.height;
}


std::ostream& operator<<(std::ostream& os, const Size& s)
{
	return os << "[" << s.width << ", " << s.height << "]";
}


Vec2 Vec2::zero{};


Vec2::Vec2()
:	x{ 0.0f }
,	y{ 0.0f }
{}


Vec2::Vec2(const float xx, const float yy)
:	x{ xx }
,	y{ yy }
{}


void Vec2::Normalize()
{
	float length{ sqrtf(x * x + y * y) };
	x /= length;
	y /= length;
}


Vec2& Vec2::operator=(const Vec2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}


Vec2& Vec2::operator+=(const Vec2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}


const Vec2 Vec2::operator+(const Vec2& other) const
{
	Vec2 result = *this;
	return result += other;
}


const bool Vec2::operator==(const Vec2& other) const
{
	return x == other.x && y == other.y;
}


std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
	return os << "[" << v.x << ", " << v.y << "]";
}


Vec3 Vec3::zero{};


Vec3::Vec3(const float xx, const float yy, const float zz)
:	x{ xx }
,	y{ yy }
,	z{ zz }
{}


Vec3::Vec3(const Vec3& other)
:	x{ other.x }
,	y{ other.y }
,	z{ other.z }
{}


Vec3::Vec3(Vec3&& other)
:	x{ other.x }
,	y{ other.y }
,	z{ other.z }
{}


Vec3 Vec3::Cross(const Vec3& a, const Vec3& b)
{
	Vec3 result{};
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}


void Vec3::Set(const float xx, const float yy, const float zz)
{
	x = xx;
	y = yy;
	z = zz;
}


void Vec3::Normalize()
{
	float length{ sqrtf(x * x + y * y + z * z) };
	x /= length;
	y /= length;
	z /= length;
}


Vec3& Vec3::operator=(const Vec3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}


Vec3& Vec3::operator+=(const Vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}


Vec3 Vec3::operator-() const
{
	return Vec3{ -x, -y, -z };
}


const bool Vec3::operator==(const Vec3& other) const
{
	return x == other.x && y == other.y && z == other.z;
}


std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
	return os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
}


Quat Quat::identity{ 0.0f, 0.0f, 0.0f, 1.0f };


Quat::Quat(float xx, float yy, float zz, float ww)
:	x{ xx }
,	y{ yy }
,	z{ zz }
,	w{ ww }
{}


Mat4 Mat4::zero{};


Mat4 Mat4::identity
{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};


Mat4::Mat4()
:	matrix{ 0.0f }
{}


Mat4::Mat4(std::initializer_list<float> list)
{
	int i{ 0 };
	for (float value : list)
	{
		matrix[i++] = value;
		if (i == 16)
		{
			break;
		}
	}
}


Mat4::Mat4(const float* const m)
{
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] = m[i];
	}
}


Mat4::Mat4(const Quat& q)
{
	float s{ 2.0f /
	         (q.x * q.x +
	          q.y * q.y +
	          q.z * q.z +
	          q.w * q.w) };

	float xs{ s * q.x };
	float ys{ s * q.y };
	float zs{ s * q.z };

	float wx{ q.w * xs };
	float wy{ q.w * ys };
	float wz{ q.w * zs };

	float xx{ q.x * xs };
	float xy{ q.x * ys };
	float xz{ q.x * zs };

	float yy{ q.y * ys };
	float yz{ q.y * zs };
	float zz{ q.z * zs };

	matrix[0]  = 1.0f - (yy + zz);
	matrix[4]  = xy - wz;
	matrix[8]  = xz + wy;
	matrix[12] = 0.0f;

	matrix[1]  = xy + wz;
	matrix[5]  = 1.0f - (xx + zz);
	matrix[9]  = yz - wx;
	matrix[13] = 0.0f;

	matrix[2]  = xz - wy;
	matrix[6]  = yz + wx;
	matrix[10] = 1.0f - (xx + yy);
	matrix[14] = 0.0f;

	matrix[3]  = 0.0f;
	matrix[7]  = 0.0f;
	matrix[11] = 0.0f;
	matrix[15] = 1.0f;
}


float& Mat4::operator[](const int index)
{
	return matrix[index];
}


float Mat4::operator[](const int index) const
{
	return matrix[index];
}


Mat4& Mat4::operator=(const Mat4& other)
{
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] = other.matrix[i];
	}
	return *this;
}


Mat4& Mat4::operator+=(const Mat4& other)
{
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] += other.matrix[i];
	}
	return *this;
}


const Mat4 Mat4::operator+(const Mat4& other) const
{
	Mat4 result = *this;
	return result += other;
}


Mat4& Mat4::operator*=(const Mat4& other)
{
	float temp[16];
	for (int i{ 0 }; i < 4; ++i)
	{
		for (int j{ 0 }; j < 4; ++j)
		{
			temp[i + j * 4] = matrix[i]      * other[j * 4]     +
			                  matrix[i +  4] * other[j * 4 + 1] +
			                  matrix[i +  8] * other[j * 4 + 2] +
			                  matrix[i + 12] * other[j * 4 + 3];
		}
	}
	for (int i{ 0 }; i < 16; ++i)
	{
		matrix[i] = temp[i];
	}
	return *this;
}


const Mat4 Mat4::operator*(const Mat4& other) const
{
	Mat4 result = *this;
	return result *= other;
}


const bool Mat4::operator==(const Mat4& other) const
{
	for (unsigned i{ 0 }; i < 16; ++i)
	{
		if (matrix[i] != other.matrix[i])
		{
			return false;
		}
	}
	return true;
}


void Mat4::Translate(const Vec3& vec)
{
	matrix[12] += vec.x;
	matrix[13] += vec.y;
	matrix[14] += vec.z;
}


void Mat4::TranslateX(const float amount)
{
	matrix[12] += amount;
}


void Mat4::TranslateY(const float amount)
{
	matrix[13] += amount;
}


void Mat4::TranslateZ(const float amount)
{
	matrix[14] += amount;
}


void Mat4::ScaleX(const float scale)
{
	matrix[0] = scale;
}


void Mat4::ScaleY(const float scale)
{
	matrix[5] = scale;
}


void Mat4::ScaleZ(const float scale)
{
	matrix[10] = scale;
}


void Mat4::Rotate(const Quat& q)
{
	Mat4 q1{
		 q.w,  q.z, -q.y, -q.x,
		-q.z,  q.w,  q.x, -q.y,
		 q.y, -q.x,  q.w, -q.z,
		 q.x,  q.y,  q.z,  q.w
	};

	Mat4 q2{
		 q.w,  q.z, -q.y,  q.x,
		-q.z,  q.w,  q.x,  q.y,
		 q.y, -q.x,  q.w,  q.z,
		-q.x, -q.y, -q.z,  q.w
	};

	*this = q1 * q2 * *this;
}


void Mat4::RotateX(const float radians)
{
	float cosrad{ static_cast<float>(std::cos(radians)) };
	float sinrad{ static_cast<float>(std::sin(radians)) };
	Mat4 rotation
	{
		1.0f,    0.0f,   0.0f, 0.0f,
		0.0f,  cosrad, sinrad, 0.0f,
		0.0f, -sinrad, cosrad, 0.0f,
		0.0f,    0.0f,   0.0f, 1.0f
	};
	*this = rotation * *this;
}


void Mat4::RotateY(const float radians)
{
	float cosrad{ static_cast<float>(std::cos(radians)) };
	float sinrad{ static_cast<float>(std::sin(radians)) };
	Mat4 rotation
	{
		cosrad, 0.0f, -sinrad, 0.0f,
		0.0f,   1.0f, 0.0f,    0.0f,
		sinrad, 0.0f, cosrad,  0.0f,
		0.0f,   0.0f, 0.0f,    1.0f
	};
	*this = rotation * *this;
}


void Mat4::RotateZ(const float radians)
{
	float cosrad{ static_cast<float>(std::cos(radians)) };
	float sinrad{ static_cast<float>(std::sin(radians)) };
	Mat4 rotation
	{
		cosrad,  sinrad, 0.0f, 0.0f,
		-sinrad, cosrad, 0.0f, 0.0f,
		0.0f,    0.0f,   1.0f, 0.0f,
		0.0f,    0.0f,   0.0f, 1.0f
	};
	*this = rotation * *this;
}


Rectangle Rectangle::zero{};


Rectangle::Rectangle()
:	x     { 0.0f }
,	y     { 0.0f }
,	width { 0.0f }
,	height{ 0.0f }
{}


const bool Rectangle::operator==(const Rectangle& other) const
{
	return x == 0.0f && y == 0.0f && width == 0.0f && height == 0.0f;
}


bool Rectangle::Contains(float xx, float yy)
{
	return (x <= xx && xx <= (x + width )) &&
	       (y <= yy && yy <= (y + height));
}


bool Rectangle::Intersects(const Rectangle& other)
{
	return (fabs(x - other.x) * 2 < (width  + other.width )) &&
	       (fabs(y - other.y) * 2 < (height + other.height));
}

bool Rectangle::Intersects(const Rectangle* other)
{
	return (fabs(x - other->x) * 2 < (width  + other->width )) &&
	       (fabs(y - other->y) * 2 < (height + other->height));
}
