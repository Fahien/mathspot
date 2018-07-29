#include "test.h"


using namespace mathspot;

int main()
{
	float a = 45.0f;
	float b = 1.0f;
	printf("radians(%f) = %f\n", a, radians(a));
	printf("degrees(%f) = %f\n", b, degrees(b));

	return EXIT_SUCCESS;
}