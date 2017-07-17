#include "test.h"

namespace mst = mathspot;


int main()
{
	mst::Rectangle r{};
	assert(r == mst::Rectangle::zero);

	return EXIT_SUCCESS;
}
