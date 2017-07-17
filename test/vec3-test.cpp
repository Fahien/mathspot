#include "test.h"

namespace mst = mathspot;


int main()
{
	mst::Vec3 a{};
	assert(a == mst::Vec3::zero);

	mst::Vec3 b{ 1.0f, 2.0f, 3.0f };
	a += b;
	assert(a == b);

	mst::Vec3 c{ mst::Vec3::cross(a, b) };
	assert(c == mst::Vec3::zero);

	return EXIT_SUCCESS;
}
