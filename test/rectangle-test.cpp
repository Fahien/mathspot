#include "test.h"

namespace mth = spot::math;


int main()
{
	mth::Rectangle r{};
	assert(r == mth::Rectangle::zero);

	return EXIT_SUCCESS;
}
