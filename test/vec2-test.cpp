#include "test.h"

namespace mst = mathspot;


int main()
{
	mst::Vec2 a{};
	assert(a == mst::Vec2::zero);

	return EXIT_SUCCESS;
}
