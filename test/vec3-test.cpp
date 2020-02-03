#include "test.h"

using namespace spot::math;


int main()
{
	Vec3 a{};
	assert(a == Vec3::zero);

	Vec3 b{ 1.0f, 2.0f, 3.0f };
	a += b;
	assert(a == b);

	a.set(-1.0f, -2.0f, -3.0f);
	assert(a == -b);

	Vec3 c{ Vec3::cross(a, b) };
	assert(c == Vec3::zero);

	return EXIT_SUCCESS;
}
