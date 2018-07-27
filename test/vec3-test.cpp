#include "test.h"

using namespace mathspot;


int main()
{
	Vec3 a{};
	assert(a == Vec3::zero);

	Vec3 b{ 1.0f, 2.0f, 3.0f };
	a += b;
	assert(a == b);

	a.Set(-1.0f, -2.0f, -3.0f);
	assert(a == -b);

	Vec3 c{ Vec3::Cross(a, b) };
	assert(c == Vec3::zero);

	return EXIT_SUCCESS;
}
