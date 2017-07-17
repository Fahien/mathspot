#include "test.h"

namespace mst = mathspot;


int main()
{
	mst::Mat4 a{};
	assert(a == mst::Mat4::zero);

	return EXIT_SUCCESS;
}
