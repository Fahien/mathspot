#ifndef MST_MATHSPOT_H
#define MST_MATHSPOT_H

#include <initializer_list>
#include <iostream>


namespace mathspot
{


const float pi{ 3.14159265f };


class Size
{
public:
	static Size null;

	Size();
	Size(int w, int h);

	Size&      operator*=(const int&   f);
	Size&      operator*=(const float& f);
	Size&      operator/=(const int&   i);
	const Size operator/ (const int&   i) const;

	const bool operator==(const Size& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Size& v);

	int width;
	int height;
};


class Vec2
{
public:
	static Vec2 zero;

	Vec2();
	Vec2(const float xx, const float yy);

	void normalize();

	Vec2&      operator= (const Vec2& other);
	Vec2&      operator+=(const Vec2& other);
	const Vec2 operator+ (const Vec2& other) const;

	const bool operator==(const Vec2& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Vec2& v);

	float x;
	float y;
};


class Vec3
{
public:
	static Vec3 zero;

	Vec3();
	Vec3(const float xx, const float yy, const float zz);

	static Vec3 cross(const Vec3& a, const Vec3& b);

	void normalize();
	Vec3& operator= (const Vec3& other);
	Vec3& operator+=(const Vec3& other);

	const bool operator==(const Vec3& other) const;

	float x;
	float y;
	float z;
};

std::ostream& operator<<(std::ostream& os, const Vec3& v);


class Quat
{
public:
	Quat() {};
	Quat(float x, float y, float z, float w);

	float x;
	float y;
	float z;
	float w;
};


class Mat4
{
public:
	static Mat4 zero;
	static Mat4 identity;

	Mat4();
	Mat4(std::initializer_list<float>);
	Mat4(const float* const m);
	Mat4(const Quat& quat);

	float&     operator[](const int index);
	float      operator[](const int index) const;
	Mat4&      operator= (const Mat4& matrix);
	Mat4&      operator+=(const Mat4& matrix);
	const Mat4 operator+ (const Mat4& other) const;
	Mat4&      operator*=(const Mat4& matrix);
	const Mat4 operator* (const Mat4& other) const;

	const bool operator==(const Mat4& other) const;

	void TranslateX(const float amount);
	void TranslateY(const float amount);
	void TranslateZ(const float amount);

	void ScaleX(const float scale);
	void ScaleY(const float scale);
	void ScaleZ(const float scale);

	void Rotate(const Quat& quat);
	void RotateX(const float radians);
	void RotateY(const float radians);
	void RotateZ(const float radians);

	float matrix[16];
};


class Rectangle
{
public:
	static Rectangle zero;

	Rectangle();

	const bool operator==(const Rectangle& other) const;

	/// Tests whether (x, y) is inside the rectangle
	bool contains(float x, float y);

	/// Tests whether this rectangle intersects another one
	bool intersects(const Rectangle& other);
	/// Tests whether this rectangle intersects another one
	bool intersects(const Rectangle* other);

	float x;
	float y;
	float width;
	float height;
};


}


#endif // MST_MATHSPOT_H
