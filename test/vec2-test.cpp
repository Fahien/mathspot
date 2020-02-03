#include "test.h"

namespace mth = spot::math;


int main()
{
	mth::Vec2 a{};
	assert(a == mth::Vec2::zero);

	return EXIT_SUCCESS;
}
