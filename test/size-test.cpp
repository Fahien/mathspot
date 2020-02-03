#include "test.h"

namespace mth = spot::math;


int main()
{
	mth::Size len{};
	assert(len == mth::Size::null);

	return EXIT_SUCCESS;
}
