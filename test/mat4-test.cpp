#include "test.h"

namespace mth = spot::math;


int main()
{
	mth::Mat4 a{};
	assert(a == mth::Mat4::zero);

	return EXIT_SUCCESS;
}
